#include "BinarySearchTree.h" 
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

int main() {
    LinkedList<int> linked;
    linked.insert_front(8);
    linked.insert_front(7);
    linked.insert_front(6);
    linked.insert_front(5);
    linked.insert_front(4);
    linked.insert_front(3);
    linked.insert_front(2);
    linked.insert_front(1);
    linked.insert_front(0);

    std::cout << "Original Linked list: "; 
    linked.print(); // sorted linked list

    // BST created from the linked list
    BinarySearchTree<int>* bst = linked.convertToBST(); 
    // linked list created from the bst
    LinkedList<int>* linked_list = bst->convertToLinkedList();
    std::cout << "Linked list from BST: "; 
    linked_list->print();
}

