#pragma once
#include <stdexcept>

template<class T>
class Stack 
{
    private:
        struct StackNode
        {
            T data;
            StackNode* next;
        };
        StackNode* top;
        int size;
        int current_size;

    public:
        Stack();
        Stack(int new_size);
        ~Stack();
        void push(const T& data);
        T pop();
        bool isEmpty();      
};


template<class T>
Stack<T>::Stack()
{
    top = nullptr;
    size = -1;
    current_size = 0;
}

template<class T>
Stack<T>::Stack(int new_size)
{
    top = nullptr;
    size = new_size;
    current_size = 0;
}

template<class T>
Stack<T>::~Stack()
{  
    while (top != nullptr) {
        StackNode* node_to_delete = top;
        top = top->next;
        delete node_to_delete;
    }
}

template<class T>
void Stack<T>::push(const T& data)
{
    if (size != -1 and current_size == size)
        throw std::invalid_argument("Error: Stack overflow!");
    
    StackNode* new_node = new StackNode();
    new_node->data = data;
    new_node->next = top;
    top = new_node;

    if (size != -1)
        current_size++;
}

template<class T>
T Stack<T>::pop()
{
    if (top == nullptr)
        throw std::invalid_argument("Error: Stack underflow!");

    T popped_item = top->data;

    StackNode* node_to_delete = top;
    top = top->next;
    delete node_to_delete;

    if (size != -1)
        current_size--;

    return popped_item;
}

template<class T>
bool Stack<T>::isEmpty()
{
    if (top == nullptr)
        return true;
    return false;
}
