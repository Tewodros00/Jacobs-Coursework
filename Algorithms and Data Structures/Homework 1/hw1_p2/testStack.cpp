/*
CH-231-A
hw1_p2.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include "Stack.h"
using namespace std;

// simple complex class with a parameteric constructor
class Complex {
    private:
        int real;
        int imaginary;
    public:
        Complex(); 
        Complex(int, int);
        Complex(const Complex&);
        friend ostream& operator<<(ostream&, const Complex&);
};

// empty constructor sets both real and imaginary parts to 1
Complex::Complex() {
    real = imaginary = 1;
}

// parameteric constructor
Complex::Complex(int real, int imaginary) {
    this->real = real, this->imaginary = imaginary;
}
// copy constructor
Complex::Complex(const Complex& c) {
    real = c.real, imaginary = c.imaginary;
}
// overloading the << operator to print complex numbers
ostream& operator<<(ostream& out, const Complex& z) {
    if (z.imaginary >= 0) {
        out << z.real << " + " << z.imaginary << "i";
    } else {
        out << z.real << " - " << -1 * z.imaginary << "i";
    }
    return out;
}

int main(void) {
    // creating an integer Stack
    Stack<int> numStack;
    cout << "=================== Integer Stack ===================" << endl;
    cout << "Entries: " << numStack.getNumEntries() << endl;
    cout << "Pushed:  ";
    for (int i = 0; i < 20; i++) {
        if (numStack.push(i))
            cout << i << " ";
    }
    cout << endl;
    cout << "Entries: " << numStack.getNumEntries() << endl;
    
    cout << "Top:     " << numStack.back() << endl;
    
    cout << "Popped:  ";
    int x;
    for (int i = 0; i < 5; i++) {
        numStack.pop(x);
        cout << x << " ";
    }
    cout << endl;
    cout << "Entries: " << numStack.getNumEntries() << endl;

    // creating a stack of Complex instances
    Stack<Complex> cStack;
    cout << "=================== Complex Stack ===================" << endl;
    cout << "Entries: " << cStack.getNumEntries() << endl;
    cout << "Pushed:  ";
    cStack.push(Complex(1, 2));
    cout << cStack.back() << "  ";
    cStack.push(Complex(3, -7));
    cout << cStack.back() << "  ";
    cStack.push(Complex(9, 6));
    cout << cStack.back() << endl;
    cout << "Entries: " << cStack.getNumEntries() << endl;

    cout << "Popped:  ";
    while(cStack.getNumEntries() > 0) {
        Complex popped;
        cStack.pop(popped);
        cout << popped << "  ";
    }
    cout << "\nEntries: " << cStack.getNumEntries() << endl;
}