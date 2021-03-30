/*
CH-231-A
hw2_p4.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<int> nums;
    nums.reserve(30);
    for (int i = 0; i < 30; i++)
        nums.push_back(i + 1);

    nums.push_back(5);

    std::reverse(nums.begin(), nums.end());

    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::replace(nums.begin(), nums.end(), 5, 129);

    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

}