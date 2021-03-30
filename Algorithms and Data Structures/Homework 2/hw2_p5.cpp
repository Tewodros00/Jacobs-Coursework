/*
CH-231-A
hw2_p5.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include <ctime>
#include <set>

int main(void) {
    std::set<int> lucky_numbers;
    srand(time(0));
    
    while (lucky_numbers.size() != 6) 
        lucky_numbers.insert(rand() % 49 + 1);
    
    for (std::set<int>::iterator i = lucky_numbers.begin();
    i != lucky_numbers.end(); i++)
        std::cout << *i << " ";
}