#include "RedBlackTree.h"
#include <iostream>

int main() {
    RedBlackTree<int> RBtree;
    RBtree.insertRB(13);
    RBtree.insertRB(44);
    RBtree.insertRB(37);
    RBtree.insertRB(7);
    RBtree.insertRB(22);
    RBtree.insertRB(16);

    std::cout << "\nInorder Traversal: ";   
    RBtree.printInorder();

    std::cout << "\nSearching for 13 and deleting that node.\n\n";
    Node<int>* node = RBtree.search(13);
    RBtree.deleteRB(node);

    std::cout << "Inorder Traversal: ";
    RBtree.printInorder();
}