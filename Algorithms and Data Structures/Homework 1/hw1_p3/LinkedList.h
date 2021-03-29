/*
CH-231-A
hw1_p3.h
Tewodros Adane
tadane@jacobs-university.de
*/
#include <iostream>
using namespace std;

template <typename T>
class node { // a single node class with previous and next pointer
    public:
        T value;
        node* next;
        node* prev;
};


template <class T>
class LinkedList {
    private:
        node<T>* head;
        node<T>* tail;
        int size;
    public:
        LinkedList(); // creates empty Linked list
        LinkedList(T); // creates a Linked list with one element
        LinkedList(const LinkedList&); // copy constructor
        ~LinkedList(); // Destructor
        bool front(T&); // returns the element at the head
        bool back(T&); // returns the element at the tail
        bool remove_front(T&); // returns and removes the element at the head
        bool remove_back(T&); // returns and removes the element at the tail
        void insert_front(T); // inserts elements at the front
        void insert_back(T); // inserts elements at the back
        int numberOfElements(); // returns the size of the list
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T data) {
    node<T>* newNode = new node<T>; // allocates memory for one node
    newNode.value = data;
    newNode.next = NULL, newNode.prev = NULL;
    head = newNode;
    tail = newNode;
    size = 1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list) {
    size = 0;
    node<T>* temp = list.head;
    // starts from the head and copies each node to the new list
    while(temp != NULL) {
        this->insert_back(temp->value);
        temp = temp->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    // starts from the head and frees memory allocated to each node
    while (head != NULL) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }   
}

template <class T>
bool LinkedList<T>::front(T& returnVal) {
    if (!head) // if empty returns false
        return false;
    returnVal = head->value;
    return true;
}

template <class T>
bool LinkedList<T>::back(T& returnVal) {
    if (!tail) // if empty returns false
        return false;
    returnVal = tail->value;
    return true;
}

template <class T>
bool LinkedList<T>::remove_front(T& returnVal) {
    if (size == 0) // if empty returns false
        return false;

    returnVal = head->value;
    // if there's only one element left sets both head and tail to NULL
    if (size == 1) { 
        delete head;
        head = NULL, tail = NULL;
    } else {
        node<T>* temp = head;
        head = head->next;
        delete temp;
        head->prev = NULL;
    }
    size--; // decrements size by one
    return true;
}

template <class T>
bool LinkedList<T>::remove_back(T& returnVal) {
    if (size == 0)
        return false;

    returnVal = tail->value;
    // if there's only one element left sets both head and tail to NULL
    if (size == 1) {
        delete tail;
        head = NULL, tail = NULL;
    } else {
        node<T>* temp = tail;
        tail = tail->prev;
        delete temp;
        tail->next = NULL;
    }
    size--; // decrements size by one
    return true;
}

template <class T>
void LinkedList<T>::insert_front(T data) {
    node<T>* newNode = new node<T>;
    newNode->value = data;
    if (size == 0) { // if empty the new element will be both head and tail
        newNode->next = newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
    size++; // increments size by 1
}

template <class T>
void LinkedList<T>::insert_back(T data) {
    node<T>* newNode = new node<T>;
    newNode->value = data;
    if (size == 0) { // if empty the new element will be both head and tail
        newNode->next = newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    size++;// increments size by 1
}

template <class T>
int LinkedList<T>::numberOfElements() {
    return size;
}