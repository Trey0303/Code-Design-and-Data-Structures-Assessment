#include <iostream>
#include "tBinaryTree.h"

int main()
{
    tBinaryTree<int> numTree;

    numTree.insert(14); //            14
    numTree.insert(21);//      7              23
    numTree.insert(7);//    5     9       19      24
    numTree.insert(5);//  4        10   18  20  23  50
    numTree.insert(9);
    numTree.insert(24);
    numTree.insert(19);
    numTree.insert(50);
    numTree.insert(20);
    numTree.insert(23);
    numTree.insert(18);
    /*numTree.insert(8);*/
    numTree.insert(10);
    numTree.insert(4);//13
    /*numTree.insert(6);*/

    tBinaryTree<int>::vertex* searchNum;//this is for finding the vertex
    numTree.search(20, searchNum);//search tree using 9 and return vertex for found value

    //before:vertex=0 data= null left=null right= null
    tBinaryTree<int> copyTree(numTree);//copy constructor
    //after:vertex=13 data= null left=null right= null

    tBinaryTree<int> copyOfACopy(copyTree);//13

    copyTree.insert(3);
    copyTree.insert(11);
    copyTree.insert(22);
    copyTree.insert(30);//17

    tBinaryTree<int> anotherCopy(copyTree);//17

    //overwrites copyTree with copyOfACopy data
    copyTree = copyOfACopy;//copy assignment

    copyTree.printPreOrder();//14,7,5,4,6,9,8,10,21,19,18,20,24,23,50
    copyTree.printPostOrder();//4,6,5,8,10,9,7,18,20,19,23,50,24,21,14
    copyTree.printInOrder();//4,5,6,7,8,9,10,14,18,19,20,21,23,24,50

    //numTree 13 copyOfACopy 13 anotherCopy 17 copyTree 13 
    copyTree.remove(searchNum);

    return 0;
}

