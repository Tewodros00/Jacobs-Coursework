#pragma once
#include <stdexcept>
#include <iostream>

enum class COLOR {
    RED = 0, 
    BLACK = 1
};

template<typename T>
struct Node
{
    T data;
    COLOR color;
    Node *left, *right, *parent;
};

template<typename T>
class RedBlackTree
{
private:
    Node<T>* root;

protected:
    void rotateLeft(Node<T>*& node);
    void rotateRight(Node<T>*& node);
    void transplant(Node<T>* node_one, Node<T>* node_two);
    Node<T>* getMinimum(Node<T>* node);
    Node<T>* getMaximum(Node<T>* node);
    COLOR getColor(Node<T>* node) const;
    void insertFixUp(Node<T>*& node);
    void deleteFixUp(Node<T>*& node);
    void deleteTree(Node<T>* node);
    void printInorder_helper(Node<T>* node) const;
public:
    RedBlackTree();
    void insertRB(T data);
    void deleteRB(Node<T>*& node);
    Node<T>* predecessor(const Node<T>*& node);
    Node<T>* successor(const Node<T>*& node);
    Node<T>* getMinimum();
    Node<T>* getMaximum();
    Node<T>* search(T data);
    void printInorder() const;
    ~RedBlackTree();
};

// ptotected methods
template<typename T>
void RedBlackTree<T>::rotateLeft(Node<T>*& node) 
{
    Node<T>* temp = node->right;
    node->right = temp->left;

    if (temp->left != nullptr)
        temp->left->parent = node;
    
    temp->parent = node->parent;
    
    if (node->parent == nullptr)
        root = temp;
    else if (node == node->parent->left)
        node->parent->left = temp;
    else
        node->parent->right = temp;

    temp->left = node;
    node->parent = temp;
}

template<typename T>
void RedBlackTree<T>::rotateRight(Node<T>*& node)
{
    Node<T>* temp = node->left;
    node->left = temp->right;

    if (temp->right != nullptr)
        temp->right->parent = node;
    
    temp->parent = node->parent;
    
    if (node->parent == nullptr)
        root = temp;
    else if (node == node->parent->left)
        node->parent->left = temp;
    else
        node->parent->right = temp;

    temp->right = node;
    node->parent = temp;
}

template<typename T>
void RedBlackTree<T>::transplant(Node<T>* node_one, Node<T>* node_two)
{
    if (node_one->parent == nullptr)
        root = node_two;
    else if (node_one == node_one->parent->left)
        node_one->parent->left = node_two;
    else
        node_one->parent->right = node_two;
    
    if (node_two != nullptr)
        node_two->parent = node_one->parent;
}

template<typename T>
Node<T>* RedBlackTree<T>::getMinimum(Node<T>* node) 
{
    Node<T>* temp = node;
    while (temp->left != nullptr) 
        temp = temp->left;
    return temp;
}

template<typename T>
Node<T>* RedBlackTree<T>::getMaximum(Node<T>* node)
{
    Node<T>* temp = node;
    while (temp->right != nullptr) 
        temp = temp->right;
    return temp;
}

template<typename T>
COLOR RedBlackTree<T>::getColor(Node<T>* node) const 
{
    if (node != nullptr)
        return node->color;
    else 
        return COLOR::BLACK;
}

template<typename T>
void RedBlackTree<T>::insertFixUp(Node<T>*& node)
{
    while (getColor(node->parent) == COLOR::RED) {
        if (node->parent == node->parent->parent->left) {
            Node<T>* uncle = node->parent->parent->right;
            Node<T>* grandParent = node->parent->parent;
            
            if (getColor(uncle) == COLOR::RED) {
                node->parent->color = COLOR::BLACK;
                uncle->color = COLOR::BLACK;
                grandParent->color = COLOR::RED;
                node = grandParent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->color = COLOR::BLACK;
                grandParent->color = COLOR::RED;
                rotateRight(grandParent);
            }
        }
        else {
            Node<T>* uncle = node->parent->parent->left;
            Node<T>* grandParent = node->parent->parent;
            
            if (getColor(uncle) == COLOR::RED) {
                node->parent->color = COLOR::BLACK;
                uncle->color = COLOR::BLACK;
                grandParent->color = COLOR::RED;
                node = grandParent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = COLOR::BLACK;
                grandParent->color = COLOR::RED;
                rotateLeft(grandParent);
            }
        }
    }
    root->color = COLOR::BLACK;
}

template<typename T>
void RedBlackTree<T>::deleteFixUp(Node<T>*& node)
{
    Node<T>* temp;
    while (node != root and node->color == COLOR::BLACK)
    {
        if (node == node->left) {
            temp = node->parent->right;
            if (temp->color == COLOR::RED) {
                temp->color = COLOR::BLACK;
                node->parent->color = COLOR::RED;
                rotateLeft(node->parent);
                temp = node->parent->right;
            }

            if (temp->left->color == COLOR::BLACK and 
                    temp->right->color == COLOR::BLACK) {
                temp->color = COLOR::RED;
                node = node->parent;
            }
            else {
                if (temp->right->color == COLOR::BLACK) {
                    temp->left->color = COLOR::BLACK;
                    temp->color = COLOR::RED;
                    rotateRight(temp);
                    temp = node->parent->right;
                }

                temp->color = node->parent->color;
                node->parent->color = COLOR::BLACK;
                temp->right->color = COLOR::BLACK;
                rotateLeft(node->parent);
                node = root;
            }
        }
        else {
            temp = node->parent->left;
            if (temp->color == COLOR::RED) {
                temp->color = COLOR::BLACK;
                node->parent->color = COLOR::RED;
                rotateRight(node->parent);
                temp = node->parent->left;
            }

            if (temp->right->color == COLOR::BLACK and 
                    temp->left->color == COLOR::BLACK) {
                temp->color = COLOR::RED;
                node = node->parent;
            }
            else {
                if (temp->left->color == COLOR::BLACK) {
                    temp->right->color = COLOR::BLACK;
                    temp->color = COLOR::RED;
                    rotateLeft(temp);
                    temp = node->parent->left;
                }
                temp->color = node->parent->color;
                node->parent->color = COLOR::BLACK;
                temp->left->color = COLOR::BLACK;
                rotateRight(node->parent);
                node = root;
            }
        }
    }
    node->color = COLOR::BLACK;
}

template<typename T>
void RedBlackTree<T>::deleteTree(Node<T>* node) 
{
    if (node == nullptr)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;    
}

template<typename T>
void RedBlackTree<T>::printInorder_helper(Node<T>* node) const 
{
    if (node == nullptr)
        return;
    printInorder_helper(node->left);
    std::cout << node->data << " ";
    printInorder_helper(node->right);
}


// public methods
template<typename T>
RedBlackTree<T>::RedBlackTree()
{
    root = nullptr;
}


template<typename T>
void RedBlackTree<T>::insertRB(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->color = COLOR::RED;
    newNode->left = newNode->right = newNode->parent = nullptr;
    
    if (root == nullptr) {
        root = newNode;
    }   
    else {
        Node<T>* parent;
        Node<T>* temp = root;
        while (temp != nullptr) {
            if (temp->data > data) {
                parent = temp;
                temp = temp->left;
            } else if (temp->data < data) {
                parent = temp;
                temp = temp->right;
            } else {
                throw std::invalid_argument
                    ("Error: duplicate items not allowed in RB BST");
            }
        }
        newNode->parent = parent;
        temp = newNode;
        
        if (temp->data < parent->data)
            parent->left = temp;
        else
            parent->right = temp;
    }    
    insertFixUp(newNode);
}

template<typename T>
void RedBlackTree<T>::deleteRB(Node<T>*& node)
{
    Node<T>* temp = node;
    COLOR originalColor = temp->color;
    Node<T>* x = nullptr;
    if (node->left == nullptr) {
        x = node->right;
        transplant(node, node->right);
    }
    else if (node->right == nullptr) {
        x = node->left;
        transplant(node, node->left);
    }
    else {
        temp = getMinimum(node->right);
        originalColor = temp->color;
        x = temp->right;
        if (temp->parent == node) {
            x->parent = temp;
        }
        else {
            transplant(temp, temp->right);
            temp->right = node->right;
            temp->right->parent = temp;
        }
        transplant(node, temp);
        temp->left = node->left;
        temp->left->parent = temp;
        temp->color = node->color;
    }

    if (originalColor == COLOR::BLACK)
        deleteFixUp(x);
}

template<typename T>
Node<T>* RedBlackTree<T>::predecessor(const Node<T>*& node)
{
    if (node->left != nullptr)
        return getMaximum(node->left);
    Node<T>* p = node->parent;
    while (p != nullptr and node == p->left) {
        node = p;
        p = p->parent;
    }
    return p;   
}

template<typename T>
Node<T>* RedBlackTree<T>::successor(const Node<T>*& node)
{
    if (node->right != nullptr)
        return getMinimum(node->right);
    Node<T>* p = node->parent;
    while (p != nullptr and node == p->right) {
        node = p;
        p = p->parent;
    }
    return p;
}

template<typename T>
Node<T>* RedBlackTree<T>::getMinimum() 
{
    return getMinimum(root);
}

template<typename T>
Node<T>* RedBlackTree<T>::getMaximum()
{
    return getMaximum(root);
}

template<typename T>
Node<T>* RedBlackTree<T>::search(T data)
{
    Node<T>* temp = root;
    while (temp != nullptr and data != temp->data) {
        if (temp->data > data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}

template<typename T>
void RedBlackTree<T>::printInorder() const 
{
    printInorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
RedBlackTree<T>::~RedBlackTree()
{
    deleteTree(root);
}
