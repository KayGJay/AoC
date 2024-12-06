#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(){
    std::ifstream infile("input.txt");
    std::vector<std::vector<int>> nums;

    while (infile.peek() != EOF){
        std::vector<int> temp;
        std::string lineStr;
        getline(infile, lineStr);
        std::istringstream line(lineStr);
        int num = 0;
        while (line >> num)
            temp.push_back(num);
        nums.push_back(temp);
    }

    int sum = 0;
    int unsafe = 0;
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

    
    return 0;
}