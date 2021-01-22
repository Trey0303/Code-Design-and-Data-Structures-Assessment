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

    num.push_front(9);
    num.push_back(20);
    num.push_front(18);

    tList<int> someNum;
    someNum.push_front(5);//tail
    someNum.push_front(1);
    someNum.push_front(7);
    someNum.push_front(2);//head

    tList<int> otherNum;

    otherNum.push_front(8);//tail
    otherNum.push_front(4);
    otherNum.push_front(3);
    otherNum.push_front(9);//head

    otherNum = someNum;

    someNum.push_front(3);

    otherNum = someNum;

    otherNum.push_front(7);

    otherNum = someNum;

    return 0;
}
