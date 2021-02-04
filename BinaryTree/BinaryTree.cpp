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
    //numTree.search(21, searchNum);//search tree using 9 and return vertex for found value


    tBinaryTree<int> copyTree(numTree);//copy constructor

    tBinaryTree<int> copyOfACopy(copyTree);

    //copyTree.insert(3);
    //copyTree.insert(11);
    //copyTree.insert(22);
    //copyTree.insert(30);

    tBinaryTree<int> anotherCopy(copyTree);

    //overwrites copyTree with copyOfACopy data
    //copyTree = copyOfACopy;//copy assignment

    copyTree.printPreOrder();//14,7,5,4,6,9,8,10,21,19,18,20,24,23,50
    copyTree.printPostOrder();//4,6,5,8,10,9,7,18,20,19,23,50,24,21,14
    copyTree.printInOrder();//4,5,6,7,8,9,10,14,18,19,20,21,23,24,50

    return 0;
}

