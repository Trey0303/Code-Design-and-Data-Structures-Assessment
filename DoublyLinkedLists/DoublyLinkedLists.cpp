#include <iostream>
#include "tList.h"

int main()
{
    tList<int> num;

    num.push_front(5);
    num.push_front(3);
    num.push_front(6);
    num.push_front(9);

    int fr = num.front();
    int bk = num.back();

    tList<int> numCopy(num);

    num.pop_front();
    num.pop_back();


    return 0;
}
