#include <iostream>
#include <fstream>
#include <vector>

const char X = 'X', M = 'M', A = 'A', S = 'S';

void getInput(std::vector<std::vector<char>>& vec, std::string filename){
    std::ifstream infile(filename);
    while (infile.peek() != EOF){
        std::vector<char> tempVec;
        std::string line;
        getline(infile, line);
        for (char ch : line)
            tempVec.push_back(ch);
        vec.push_back(tempVec);
    }
    infile.close();
}

bool testLeft(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (ix < 3)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy).at(ix - 1) == M && 
        vec.at(iy).at(ix - 2) == A && vec.at(iy).at(ix - 3) == S)
        return true;
    return false;
}

bool testRight(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (ix > vec.at(iy).size() - 4)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy).at(ix + 1) == M && 
        vec.at(iy).at(ix + 2) == A && vec.at(iy).at(ix + 3) == S)
        return true;
    return false;
}

bool testUp(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (iy < 3)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy - 1).at(ix) == M && 
        vec.at(iy - 2).at(ix) == A && vec.at(iy - 3).at(ix) == S)
        return true;
    return false;
}

bool testDown(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (iy > vec.size() - 4)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy + 1).at(ix) == M && 
        vec.at(iy + 2).at(ix) == A && vec.at(iy + 3).at(ix) == S)
        return true;
    return false;
}

bool upLeft(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (ix < 3 || iy < 3)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy - 1).at(ix - 1) == M && 
        vec.at(iy - 2).at(ix - 2) == A && vec.at(iy - 3).at(ix - 3) == S)
        return true;
    return false;
}

bool upRight(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (ix > vec.at(iy).size() - 4 || iy < 3)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy - 1).at(ix + 1) == M && 
        vec.at(iy - 2).at(ix + 2) == A && vec.at(iy - 3).at(ix + 3) == S)
        return true;
    return false;
}

bool downLeft(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (ix < 3 || iy > vec.size() - 4)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy + 1).at(ix - 1) == M && 
        vec.at(iy + 2).at(ix - 2) == A && vec.at(iy + 3).at(ix - 3) == S)
        return true;
    return false;
}

bool downRight(std::vector<std::vector<char>>& vec, std::vector<std::vector<char>>::size_type iy,
               std::vector<char>::size_type ix){
    if (ix > vec.at(iy).size() - 4 || iy > vec.size() - 4)
        return false;
    if (vec.at(iy).at(ix) == X && vec.at(iy + 1).at(ix + 1) == M && 
        vec.at(iy + 2).at(ix + 2) == A && vec.at(iy + 3).at(ix + 3) == S)
        return true;
    return false;
}

int findMatches(std::vector<std::vector<char>>& vec){
    int matchSum = 0;
    for (std::vector<std::vector<char>>::size_type i = 0; i < vec.size(); i++){
        std::vector<char>::size_type j = 0;
        while (j < vec.at(i).size()){
            std::cout << "i: " << i << " j: " << j << std::endl;
            //std::cout << "i: " << i << " " << "j: " << j << std::endl;
            std::cout << "Test\n";
            if (testLeft(vec, i, j)){
                std::cout << "idx of left match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (testRight(vec, i, j)){
                std::cout << "idx of right match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (testUp(vec, i, j)){
                std::cout << "idx of up match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (testDown(vec, i, j)){
                std::cout << "idx of down match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (upLeft(vec, i, j)){
                std::cout << "idx of up/left match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (upRight(vec, i, j)){
                std::cout << "idx of up/right match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (downLeft(vec, i, j)){
                std::cout << "idx of down/left match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            std::cout << "Test\n";
            if (downRight(vec, i, j)){
                std::cout << "idx of down/right match is " << i << ", " << j << std::endl;
                matchSum++;
            }
            j++;
        }
    }
    return matchSum;
}

int main(){
 /* std::vector<std::vector<char>> puzVec;
    getInput(puzVec, "input.txt"); */

    std::vector<std::vector<char>> testVec;

    getInput(testVec, "input.txt");
    for(std::vector<char> list : testVec){
        for (char let : list){
            std::cout << let << " ";
        }
        std::cout << std::endl;
    }
    int matches = findMatches(testVec);
    std::cout << matches << std::endl;
    return 0;
}