#include <iostream>
#include "tBinaryTree.h"

int main()
{
    tBinaryTree<int> numTree;

    numTree.insert(14);
    numTree.insert(21);
    numTree.insert(6);
    numTree.insert(5);
    numTree.insert(9);
    numTree.insert(24);
    numTree.insert(19);

    tBinaryTree<int>::vertex searchNum;//this is for finding the vertex
    numTree.search(21, searchNum);//search tree using 9 and return vertex for found value

    //numTree.~tBinaryTree();

    tBinaryTree<int> copyTree(numTree);

    tBinaryTree<int> copyOfACopy(copyTree);

    copyTree.insert(7);
    copyTree.insert(8);
    copyTree.insert(25);
    copyTree.insert(30);

    //overwrites copyTree with copyOfACopy data
    copyTree = copyOfACopy;

    return 0;
}

