
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

    //removing elements from array
    original.pop_back(); 
    original.pop_back();
    original.pop_back();
    original.pop_back();

    //tests to see if array is empty or not
    original.print();
    original.empty();
    original.shrink_to_fit();

    //adding elements to array
    original.push_back(4);
    original.push_back(5);
    original.push_back(6);
    original.shrink_to_fit();
    original.print();

    //clears all elements in array
    original.clear();
    original.shrink_to_fit();
    original.print();

    //resize to a bigger number
    original.resize(10);
    original.print();

    //resize to a smaller number
    original.resize(5);
    original.print();

    tVector<int> stlNumbers;

    stlNumbers.push_back(5);
    stlNumbers.push_back(7);
    stlNumbers.push_back(9);
    stlNumbers.push_back(12);

    for (auto it = stlNumbers.begin();it != stlNumbers.end();++it) {
        
        std::cout << (*it) << std::endl;
    }

    auto it = stlNumbers.begin();
    int itVal = *it;

    return 0;
}
