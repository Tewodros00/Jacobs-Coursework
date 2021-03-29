/*
CH-231-A
hw1_p5.cpp
Tewodros Adane
tadane@jacobs-university.de
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    vector<string> words; // creates an empty vector
    

    string word; 
    while (true) { // reads each line and adds the string to the vector
        getline(cin, word);
        if (word == "END")
            break;
        words.push_back(word);
    }
    
    unsigned int size = words.size();

    // if the size if greater than 5 it switches the second and fifth element
    if (size > 4) {
        string temp = words[1];
        words[1] = words[4];
        words[4] = temp;
    }

    // if there is at least one word replaces the last word with "???"
    if (size > 0)
        words[words.size() - 1] = "???";


    // prints the vector by the index operator separated by commas
    for (unsigned int i = 0; i < size; i++) {
        (i == size - 1) ? cout << words[i]: cout << words[i] + ", ";
    }
    cout << endl;
    
    // prints the vector by the iterator separated by colons
    vector<string>::iterator iter = words.begin();
    while (iter != words.end()) {
        (iter + 1 == words.end()) ? cout << *iter : cout << *iter + " : ";
        iter++;
    }
    cout << endl;
    
    // prints the vector in reverse by the iterator separated by spaces
    iter = words.end() - 1;
    while (true) {
        cout << *iter + " ";
        iter--;
        if (iter == words.begin()) {
            cout << *iter;
            break;
        }
    }

}