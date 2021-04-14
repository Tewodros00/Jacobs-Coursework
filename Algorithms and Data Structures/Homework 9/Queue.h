#pragma once

#include <stdexcept>
#include "Stack.h"

template<class T>
class Queue
{
    private:
        Stack<T> in;
        Stack<T> out;

    public:
        Queue();
        ~Queue();
        void enqueue(T new_data);
        T dequeue();
        bool isEmpty();
};


template<class T>
Queue<T>::Queue(){}

template<class T>
Queue<T>::~Queue(){}

template<class T>
void Queue<T>::enqueue(T new_data) {
    in.push(new_data);
}

template<class T>
T Queue<T>::dequeue() {
    if (in.isEmpty() and out.isEmpty())
        throw std::invalid_argument("Error: Queue underflow!");

    if (out.isEmpty())
        while (! in.isEmpty()) 
            out.push(in.pop());
    
    return out.pop();
}

template<class T>
bool Queue<T>::isEmpty() {
    if (in.isEmpty() and out.isEmpty())
        return true;
    return false;
}