/*
CH-231-A
hw1_p1.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
using namespace std;

// simple complex class with an empty and parameteric constructor, and has the
// '==' operator overloaded
class Complex {
    private:
        int real;
        int imaginary;
    public:
        Complex(); 
        Complex(int, int);
        bool operator==(const Complex& complex) const;
};

// empty constructor sets both real and imaginary parts to 1
Complex::Complex() {
    real = imaginary = 1;
}

// parameteric constructor
Complex::Complex(int real, int imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

// overloaded '==' operator returns true if real equals real and imaginary 
// equals imaginary
bool Complex::operator==(const Complex& c) const {
    return real == c.real && imaginary == c.imaginary;
}

// template for a linear search function. It takes an array of type T, size of
// the array and an element to search of type T. 
template <class T>
int array_search(T array[], int dim, T toSearch) {
    for (int i = 0; i < dim; i++) {
        // if current element equals toSearch returns the current index 
        if (array[i] == toSearch)
            return i;
    }
    return -1;
}


int main(void) {
    // using the function to search through a int array
    int numArray[] = {1, 3, 2, 12, 32, 5, 9, 0};
    cout << "Searching number array: " << endl;
    cout << array_search<int>(numArray, 8, 9) << endl;

    // using the function to search through a string array
    string strArray[] = {"Person", "complex", "water", "imaginary"};
    cout << "Searching string array: " << endl;
    cout << array_search<string>(strArray, 4, "hi") << endl;

    // using the function to search through an array of Complex objects
    Complex complexArray[] = {Complex(3, -1), Complex(7, 0), Complex(1, 1)};
    cout << "Searching Complex array: " << endl;
    cout << array_search<Complex>(complexArray, 3, Complex()) << endl;
}
