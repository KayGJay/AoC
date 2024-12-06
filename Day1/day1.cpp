#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(){
    std::ifstream infile("aocinput1.txt");
    std::vector<int> list1;
    std::vector<int> list2;
    
    int num1, num2;
    while (infile >> num1 >> num2){
        list1.push_back(num1);
        list2.push_back(num2);
    }

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int sum = 0;
    for (int j = 0; j < list1.size(); j++){
        sum += abs(list1.at(j) - list2.at(j));
    }

    std::cout << sum << std::endl;

    sum = 0;

    for (int i : list1){
        int count = std::count(list2.begin(), list2.end(), i);
        sum += i * count;
    }
    std::cout << sum << std::endl;
    
    infile.close();

    return 0;
}