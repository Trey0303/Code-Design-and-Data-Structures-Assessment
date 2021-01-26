#include <iostream>
#include "tBinaryTree.h"

int main()
{
    tBinaryTree<int> numTree;

    numTree.insert(6);
    numTree.insert(9);
    numTree.insert(14);
    numTree.insert(21);
    numTree.insert(12);

    //numTree.search(9);

    return 0;
}

