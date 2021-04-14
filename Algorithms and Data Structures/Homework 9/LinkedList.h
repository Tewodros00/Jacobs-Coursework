#pragma once
#include <iostream>
#include "BinarySearchTree.h"

template<class T>
class BinarySearchTree;

template<class T>
class LinkedList
{
    private:
        struct LinkedListNode
        {
            T data;
            LinkedListNode* next;
        };

        LinkedListNode* head;
        int size;
        void convertToBST_helper
                (BinarySearchTree<T>* bst, int left, int right);
        
    public:
        LinkedList();
        ~LinkedList();
        T getElementAt(int n);
        void insert_front(T new_data);
        BinarySearchTree<T>* convertToBST();
        void print();
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    while(head->next != nullptr) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
template<class T>
T LinkedList<T>::getElementAt(int n) {
    if (n >= size or n < 0)
        throw std::invalid_argument("Error: acessing non existing element");
    LinkedListNode* temp = head;
    for (int i = 0; i < n; i++)
        temp = temp->next;
    return temp->data;
}

template<class T>
void LinkedList<T>::insert_front(T new_data) 
{
    LinkedListNode* new_node = new LinkedListNode();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    size++;
}

template<class T>
BinarySearchTree<T>* LinkedList<T>::convertToBST() 
{
    BinarySearchTree<T>* bst = new BinarySearchTree<T>();
    convertToBST_helper(bst, 0, size);
    return bst;
}

template<class T>
void LinkedList<T>::convertToBST_helper
        (BinarySearchTree<T>* bst, int left, int right) 
{
    if (right - left == 0) {
        return;
    } else {
        int mid = left + ((right - left) / 2);
        bst->insert(getElementAt(mid));
        convertToBST_helper(bst, left, mid);
        convertToBST_helper(bst, mid + 1, right);
    }
}

template<class T>
void LinkedList<T>::print() 
{
    LinkedListNode* temp = head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}