/*
CH-231-A
hw1_p2.h
Tewodros Adane
tadane@jacobs-university.de
*/

template<class T>
class Stack {
    private:
        T* array;
        int size;
        int top;
    public:
        Stack(); // creates an a stack of size 10
        Stack(int); // creates a stack and allocates memory for a given size
        Stack(const Stack&); // copy constructor
        ~Stack(); // Destructor
        bool push(T); // pushes elements to the top of the stack
        bool pop(T&); // returns and removes an element from the top
        T back(void); // returns the top element without deleting it
        int getNumEntries(); // gives the size of the stack
};

template<class T>
Stack<T>::Stack() {
    array = new T[10];
    size = 10;
    top = -1; // when top is -1 it means there is nothing in the stack
}

template<class T>
Stack<T>::Stack(int size) {
    array = new T[size];
    this->size = size;
    top = -1;
}

template<class T>
Stack<T>::Stack(const Stack& stack) {
    array = new T[stack.size];
    this->size = stack.size;
    this->top = stack.top;
    // copies every element from the stack to the new stack
    for (int i = 0; i < top; i++) 
        array[i] = stack.array[i];    
}

template<class T>
Stack<T>::~Stack() {
    delete[] array; // frees the memory allocated for the stack
}


template<class T>
bool Stack<T>::push(T item) {
    if (top + 1 == size) // if the stack is full returns false
        return false;
    array[++top] = item;
    return true;
}

template<class T>
bool Stack<T>::pop(T& var) {
    if (top == -1) // if stack is empty returns false 
        return false;
    var = array[top--];
    return true;
}

template<class T>
T Stack<T>::back(void) {
    return array[top];
}

template<class T>
int Stack<T>::getNumEntries() {
    return top + 1;
}