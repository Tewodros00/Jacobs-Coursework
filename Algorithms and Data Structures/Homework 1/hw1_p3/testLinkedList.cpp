/*
CH-231-A
hw1_p3.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(void) {
    LinkedList<int> list;
    list.insert_back(1);
    list.insert_back(2);
    list.insert_back(3);
    list.insert_front(4);
    list.insert_front(5);
    int fr, ba;
    cout << "Number of elements: " << list.numberOfElements() << endl;
    list.remove_back(ba);
    cout << "removed " << ba << " from the back." << endl;
    list.remove_front(fr);
    cout << "removed " << fr << " from the front." << endl; 
    cout << "Number of elements: " << list.numberOfElements() << endl;
    list.front(fr);
    list.back(ba);
    cout << "Current element on the front is " << fr << endl;
    cout << "Current element on the front is " << ba << endl;

}