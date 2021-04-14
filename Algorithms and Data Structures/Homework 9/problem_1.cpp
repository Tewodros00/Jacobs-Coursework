#include <iostream>
#include <stdexcept>
#include "Stack.h"
#include "Queue.h"

int main() {
    std::cout << "=============== Stack test ===============\n\n";
    std::cout << "Pushing to a Stack of size 5:\n";
    Stack<int> int_stack = Stack<int>(5);
    for (int i = 0; i < 7; i++) { 
        try {
            std::cout << "pushing: " << i << " ... ";
            int_stack.push(i);
            std::cout << "pushed\n";
        } catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }        
    }
    
    std::cout << "\nPopping from the stack:\n";

    for (int i = 0; i < 6; i++) {
        try {
            int data = int_stack.pop();
            std::cout << "Popped: " << data << "\n";
        } catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }       
    }

    std::cout << "\n=============== Queue test ===============\n\n";
    std::cout << "Adding elements to a new Queue:\n";
    Queue<int> int_queue;
    for (int i = 0; i < 5; i++) {
        int_queue.enqueue(i);
        std::cout << "Enqueued: " << i << "\n";
    }

    std::cout << "\nRemoving elements from the Queue:\n";

    for (int i = 0; i < 7; i++) {
        try {
            int dequeued = int_queue.dequeue();
            std::cout << "Dequeued: " << dequeued << "\n";
        } catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }
}