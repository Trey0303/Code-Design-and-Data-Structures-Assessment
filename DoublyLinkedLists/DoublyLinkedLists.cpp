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

    tList<int> removeNum;

    removeNum.push_front(11);//tail
    removeNum.push_front(15);
    removeNum.push_front(15);
    removeNum.push_front(31);
    removeNum.push_front(4);//head

    removeNum.remove(15);//remove 15 from list

    std::cout << removeNum.empty() << std::endl;//0 = false

    removeNum.clear();

    std::cout << removeNum.empty() << std::endl;//1 = true

    tList<int> resizeList;

    resizeList.push_front(7);//tail
    resizeList.push_front(5);
    resizeList.push_front(1);
    resizeList.push_front(3);
    resizeList.push_front(4);//head

    resizeList.resize(8);//grow

    resizeList.resize(2);//shrink

    tList<int> things;

    things.push_front(7);//tail
    things.push_front(5);
    things.push_front(1);
    things.push_front(3);
    things.push_front(4);//head

    for (auto it = things.begin(); it != things.end(); ++it) {
        std::cout << (*it) << std::endl;
    }

    things.insert(things.begin()++, 5);

    return 0;
}
