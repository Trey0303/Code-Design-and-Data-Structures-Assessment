#include <iostream>
#include "tBinaryTree.h"

int main()
{
    tBinaryTree<int> numTree;

    numTree.insert(6);
    numTree.insert(5);
    numTree.insert(9);
    numTree.insert(14);
    numTree.insert(21);
    numTree.insert(12);
    numTree.insert(7);

    tBinaryTree<int>::vertex searchNum;//this is for finding the vertex
    numTree.search(9, searchNum);//search tree using 9 and return vertex for found value

    tBinaryTree<int> copyTree(numTree);



    return 0;
}

