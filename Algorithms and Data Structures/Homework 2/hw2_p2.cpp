/*
CH-231-A
hw2_p2.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    deque<float> A;
    while (true) {
        float num;
        cin >> num;
        if (num == 0)
            break;
        (num > 0) ? A.push_back(num) : A.push_front(num);
    }  

    cout << "A: ";
    for (float a : A)
        cout << a << " ";
    cout << "\n\n";

    deque<float>::iterator i = A.begin();
    while (i != A.end()) {
        if (*i > 0)
            break;
        i++;
    }
    A.insert(i, 0);

    cout << "A: ";
    for (deque<float>::iterator i = A.begin(); i != A.end();){
        cout << *i;
        (++i != A.end()) ? cout << " : " : cout << endl;
    }









}
