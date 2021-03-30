/*
CH-231-A
hw2_p6.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <map>
using std::string;


int main(void) {
    std::map<string, string> birthdays;

    std::ifstream input("data.txt");
    if (!input.is_open()) {
        std::cerr << "File not found!" << std::endl;
        exit(1);
    }

    string fname, lname, bday;
    
    while (input >> fname >> lname >> bday) {
        birthdays[fname + " " + lname] = bday;
    }

    // for (std::map<string, string>::iterator i = birthdays.begin();
    // i != birthdays.end(); i++) {
    //     std::cout << i->first << " : " << i->second << std::endl;
    // }
    string name;
    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::map<string, string>::iterator i = birthdays.find(name);
    if (i == birthdays.end()) {
        std::cout << "Name not found!" << std::endl;
    } else {
        std::cout << "Birthday: " << i->second << std::endl;
    }
}