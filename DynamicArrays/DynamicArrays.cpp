
#include <iostream>
#include "tVector.h"


int main()
{
    tVector<int> original;

    original.push_back(4);
    original.push_back(5);
    original.push_back(6);
    original.shrink_to_fit();

    tVector<int> copy = original;
    copy.pop_back(); // removes from the copy array, but not the original
    copy.pop_back();
    copy.pop_back();

    std::cout << original.size() << std::endl;// 3
    std::cout << copy.size() << std::endl;// 0

    int val = original.at(0);
    
    //print original
    original.print();

    original[0] = 7;

    original.print();

    original[10] = 30; //wont change because 10 is out of arrays range
    
    //print original
    original.print();

    original[1] = 69;

    original.print();

    original[10] = 30; //wont change because 10 is out of arrays range

    //print original
    original.print();
    original.push_back(6);
    original.print();

    original.empty();

    original.shrink_to_fit();

    original.pop_back(); 
    original.pop_back();
    original.pop_back();
    original.pop_back();

    original.print();
    original.empty();
    original.shrink_to_fit();

    original.push_back(4);
    original.push_back(5);
    original.push_back(6);
    original.shrink_to_fit();
    original.print();

    original.clear();
    original.shrink_to_fit();
    original.print();

    original.resize(10);

    return 0;
}
