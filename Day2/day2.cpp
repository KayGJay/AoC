#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

/* {{7, 6, 4, 2, 1}, {1, 2, 7, 8, 9}, {9, 7, 6, 2, 1},
                                          {1, 3, 2, 4, 5}, {8, 6, 4, 4, 1}, {1, 3, 6, 7, 9}}; */


//Didn't implement til part 2
bool isSafe(std::vector<int>);
bool isSafe2(std::vector<int>);

int main(){
    std::ifstream infile("input.txt");
    std::vector<std::vector<int>> nums;
    int inpNum;
    while (infile.peek() != EOF){
        std::vector<int> temp;
        std::string lineStr;
        getline(infile, lineStr, '\n');
        std::istringstream line(lineStr);
        while (line >> inpNum && line.peek() != 'n'){
            temp.push_back(inpNum);
        }
        nums.push_back(temp);
}
        


    int sum = 0; 
    for (std::vector list : nums){
        std::string inc_dec;
        std::string temp_inc_dec;
        int dif = list.at(0) - list.at(1);
        if (list.at(0) < list.at(1))
            temp_inc_dec = inc_dec = "inc";
        else if (list.at(0) > list.at(1))
            temp_inc_dec = inc_dec = "dec";
        else
            temp_inc_dec = inc_dec = "same";
        if (inc_dec != "same" && dif >= -3 && dif <= 3 && dif != 0)
            for (int i = 1; i < list.size() - 1; i++){
                dif = list.at(i) - list.at(i + 1);
                if (dif < 0){
                    temp_inc_dec = "inc";
                }    
                else if (dif > 0)
                    temp_inc_dec = "dec";
                else
                    temp_inc_dec = "same";
                if (temp_inc_dec != inc_dec || dif > 3 || dif < -3)
                    break;
            }

        if (temp_inc_dec == inc_dec && dif <= 3  && dif >= -3 && dif != 0){
            //Print safe vectors for debugging
            sum++;
            std::cout << "[";
            for (int elem : list){
                std::cout << elem << ", ";
            }
            std::cout << "] is safe\n";
        }    
    }

    std::cout << sum << std::endl;

    //End part1
    sum = 0;
    bool second_pass = false;
    for (std::vector<int>& list : nums){
        if (isSafe2(list))
            sum++;
    }

    std::cout << sum << std::endl;
}

bool isSafe(std::vector<int> vec){
    bool inc = true;
    bool dec = true;
    for (std::vector<int>::size_type i = 1; i < vec.size(); i++){
        int dif = vec.at(i-1) - vec.at(i);
        if (dif < -3 || dif > 3 || dif == 0)
            return false;
        else{
            if (dif > 0)
                inc = false;
            else
                dec = false;
        }
    }
    return inc || dec;
}

bool isSafe2(std::vector<int> vec){
    if (isSafe(vec))
        return true;
    for (std::vector<int>::size_type i = 0; i < vec.size(); i++){
        std::vector<int> skipper;
        for (std::vector<int>::size_type j = 0; j < vec.size(); j++){
            if (i != j)
                skipper.push_back(vec.at(j));
        }
        if (isSafe(skipper))
            return true;
    }
    return false;
}