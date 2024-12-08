#include <iostream>
#include <sstream>
#include <regex>
#include <vector>
#include <fstream>


const std::regex PATTERN("mul\\(\\d{1,3},\\d{1,3}\\)");
const std::string DONT = "don't()";
const std::string DO = "do()";

std::string getInput(std::string filename){
    std::ifstream infile(filename);
    std::string tempString;
    std::string fullString;
    while (infile.good()){
        getline(infile, tempString);
        fullString += tempString;
    }
    infile.close();
    return fullString;
}

std::string afterMatch(std::string toMatch){
    std::smatch match;
    std::string tempStr;
    if (std::regex_search(toMatch, match, PATTERN)){
        int pos = toMatch.find(match.str());
        //std::cout << "Match! " << match.str() << " at " << pos << std::endl; //debug
        tempStr = toMatch.substr(pos + match.str().size());
    }
    //std::cout << "new string: " << tempStr << std::endl;
    return tempStr;
}

std::string processNum(std::string toSlice){
    return std::string(toSlice.begin() + 4, toSlice.begin() + (toSlice.size() - 1));
}

void addNums(std::vector<int>& numVec, std::string s){
    int commaPos = s.find(',');
    numVec.push_back(stoi(s.substr(0, commaPos)));
    numVec.push_back(stoi(s.substr(commaPos + 1, s.size())));
}

std::string doorDont(std::string toProcess){
    int frontPos = 0;
    int backPos = 0;
    std::string tempString;
    int i = 1;
    while (toProcess.find(DO) != std::string::npos){
        backPos = toProcess.find(DONT);
        std::cout << "Loop number: " << i  << " frontPos: " << frontPos << " backPos: " << backPos << std::endl;
        i++;
        tempString += toProcess.substr(frontPos, backPos - frontPos);
        std::cout << "Successfully concat to tempString\n";
        if (!(toProcess.size() - backPos + 7 - frontPos < toProcess.size()))
            break;
        toProcess = toProcess.substr(backPos + 7 - frontPos, toProcess.size() - backPos + 7 - frontPos);
        std::cout << "Succesfully sliced toProcess\n";
        if (toProcess.find(DO) != std::string::npos)
            toProcess = toProcess.substr(toProcess.find(DO), toProcess.size() - toProcess.find(DO));
        //std::cout << "tempString " << i << ":\n" << tempString << std::endl;
    }
    return tempString;
}

int main(){
    std::string inp = "asdf som e mul( 2,3)spamul(32,2)cemul(333,222)s";
    std::string inpStr = getInput("input.txt");
    std::vector<std::string> matchVec;
    std::string backStr = inpStr;
    std::smatch match; 
    std::vector<std::string> size;
    bool noMatch = false;
    std::vector<int> numList;


    while (!noMatch){
        if (std::regex_search(backStr, match, PATTERN)){
            matchVec.push_back(processNum(match.str()));
            backStr = afterMatch(backStr);
            //std::cout << "New string after match " << backStr << std::endl;
        }
        else
            noMatch = true;
    }
    /* 
    for (std::string func : matchVec){
        std::cout << func << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for (int val : numList){
        std::cout << val << ", ";
    } */
    for (std::string pair : matchVec){
        addNums(numList, pair);
    }

    int sum = 0;
    for (std::vector<int>::size_type i = 0; i < numList.size() - 1; i += 2){
        sum += (numList.at(i) * numList.at(i + 1));
    }
    std::cout << sum << std::endl;

    //Part 2

    /* std::string test = "111something1do()111so1mething11don't()00sometingdo00do()1111don't()000";

    std::cout << doorDont(test) << std::endl; */

    std::string doStr = doorDont(inpStr);
    backStr = doStr;
    noMatch = false;
    numList.clear();
    matchVec.clear();

    while (!noMatch){
        if (std::regex_search(backStr, match, PATTERN)){
            matchVec.push_back(processNum(match.str()));
            backStr = afterMatch(backStr);
        }
        else
            noMatch = true;
    }

    numList.clear();

    for (std::string pair : matchVec){
        addNums(numList, pair);
    }

    sum = 0;

    for (std::vector<int>::size_type i = 0; i < numList.size() - 1; i += 2){
        sum += (numList.at(i) * numList.at(i + 1));
    }
    
    std::cout << sum << std::endl;
    std::ofstream outfile("output.txt");
    outfile << doStr;

    return 0;
}