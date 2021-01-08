
#include <iostream>
#include "tVector.h"


int main()
{
    tVector<int> original;

    original.push_back(4);
    original.push_back(5);
    original.push_back(6);

    tVector<int> copy = original;
    copy.pop_back(); // removes from the copy array, but not the original
    copy.pop_back();
    copy.pop_back();

    int val = original.at(0);



    return 0;
}
