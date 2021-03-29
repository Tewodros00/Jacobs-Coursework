/*
CH-231-A
hw1_p4.cpp
Tewodros Adane
tadane@jacobs-university.de
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    vector<string> words; // creates an empty vector
    
    string word;
    while (true) { // reads the words into the vector until 'END' is entered
        cin >> word;
        if (word == "END")
            break;
        words.push_back(word);
    }
    
    // prints the words by the index operator
    for (unsigned int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    // creates an iterator and prints the vector using the iterator
    vector<string>::iterator iter = words.begin();
    while (iter != words.end())
    {
        (iter + 1 == words.end()) ? cout << *iter : cout << *iter + ", ";
        iter++;
    }
    
}