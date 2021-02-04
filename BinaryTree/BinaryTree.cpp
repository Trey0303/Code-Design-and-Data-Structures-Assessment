#include <iostream>
#include "tBinaryTree.h"

int main()
{
    tBinaryTree<int> numTree;

    numTree.insert(14); //            14
    numTree.insert(21);//      7              21
    numTree.insert(7);//    5     9       19      24
    numTree.insert(5);//  4  6  8  10   18  20  23  50
    numTree.insert(9);
    numTree.insert(24);
    numTree.insert(19);
    numTree.insert(50);
    numTree.insert(20);
    numTree.insert(23);
    numTree.insert(18);
    numTree.insert(8);
    numTree.insert(10);
    numTree.insert(4);
    numTree.insert(6);

    tBinaryTree<int>::vertex searchNum;//this is for finding the vertex
    numTree.search(21, searchNum);//search tree using 9 and return vertex for found value


    tBinaryTree<int> copyTree(numTree);//copy constructor

    tBinaryTree<int> copyOfACopy(copyTree);

    copyTree.insert(7);
    copyTree.insert(8);
    copyTree.insert(25);
    copyTree.insert(30);

    tBinaryTree<int> anotherCopy(copyTree);

    //overwrites copyTree with copyOfACopy data
    copyTree = copyOfACopy;//copy assignment

    return 0;
}

