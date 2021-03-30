/*
CH-231-A
hw2_p1.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main(void) {
    list<int> A, B;
    while (true) {
        int num;
        cin >> num;
        if (num < 1)
            break;
        A.push_back(num);
        B.push_front(num);
    }  

    cout << "A: ";
    for (int a : A)
        cout << a << " ";
    cout << "\n\n";
    
    ofstream output("listB.txt");
    for (int b : B)
        output << b << " ";
    output.close();

    A.push_back(A.front());
    A.pop_front();
    B.push_back(B.front());
    B.pop_front();

    cout << "A: ";
    for (list<int>::iterator i = A.begin(); i != A.end();){
        cout << *i;
        (++i != A.end()) ? cout << ", " : cout << endl;
    }
    
    cout << "B: ";
    for (list<int>::iterator i = B.begin(); i != B.end();){
        cout << *i;
        (++i != B.end()) ? cout << ", " : cout << endl;
    }

    cout << endl;

    for (list<int>::iterator i = B.begin(); i != B.end(); i++)
        A.push_back(*i);

    A.sort();

    cout << "Merged: ";
    for (int a : A)
        cout << a << " ";
    cout << endl;
}
