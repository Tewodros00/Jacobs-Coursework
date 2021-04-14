#pragma once
#include <stdexcept>
#include "LinkedList.h"

template<class T>
class LinkedList;

template<class T>
class BinarySearchTree
{
    private:
        struct BSTnode
        {
            T data;
            BSTnode* left;
            BSTnode* right;
        };
   
        BSTnode* root;
   
        void convertToLinkedList_helper
                (LinkedList<T>* linked_list, BSTnode* node);
        
        void deleteTree(BSTnode* node);

    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(T new_data);
        LinkedList<T>* convertToLinkedList();

};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteTree(root);
}

template<class T>
void BinarySearchTree<T>::deleteTree(BSTnode* node) {
    if (node == nullptr)
        return
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}


template<class T>
void BinarySearchTree<T>::insert(T new_data)
{
    if (root == nullptr) {
        root = new BSTnode();
        root->data = new_data;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        BSTnode* prev;
        BSTnode* temp = root;
        while(temp != nullptr) {
            if (new_data < temp->data) {
                prev = temp;
                temp = temp->left;
            } else if (new_data > temp->data) {
                prev = temp;
                temp = temp->right;
            } else { 
                throw std::invalid_argument
                    ("Error: duplicate items not allowed in BST");
            }
        }
        temp = new BSTnode();
        temp->data = new_data;
        temp->left = nullptr;
        temp->right = nullptr;

        if (temp->data < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}

template<class T>
LinkedList<T>* BinarySearchTree<T>::convertToLinkedList()
{
    LinkedList<T>* linked_list = new LinkedList<T>();
    convertToLinkedList_helper(linked_list, root);
    return linked_list;
}

template<class T>
void BinarySearchTree<T>::convertToLinkedList_helper
        (LinkedList<T>* linked_list, BSTnode* node)
{
    if (node == nullptr)
        return;
    convertToLinkedList_helper(linked_list, node->right);
    linked_list->insert_front(node->data);
    convertToLinkedList_helper(linked_list, node->left);
}