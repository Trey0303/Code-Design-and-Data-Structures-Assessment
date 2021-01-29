#include <iostream>
#include "Hashing.h"

int main()
{
    //negative numbers wont work with this type(uint32_t)
    uint32_t firstHash = hash<uint32_t>(5);
    uint32_t secondHash = hash<uint32_t>(2);
    uint32_t thirdHash = hash<uint32_t>(4);

    //specializing for comman types
    //int
    uint32_t eighthHash = hash<int>(5);
    uint32_t ninthHash = hash<int>(2);
    uint32_t tenthHash = hash<int>(4);

    //char
    uint32_t eleventhHash = hash<char>('w');
    uint32_t twelfthHash = hash<char>('a');
    uint32_t thirteenthHash = hash<char>('s');

    //bool
    uint32_t fourteenthHash = hash<bool>(false);
    uint32_t fifteenthHash = hash<bool>(true);
    //uint32_t sixteenthHash = hash<bool>();

    //float
    uint32_t floatOne = hash<float>(3.0f);
    uint32_t floatTwo = hash<float>(4.0f);
    uint32_t floatThree = hash<float>(6.0f);

    //string
    uint32_t firstWord = hash("words");

    return 0;
}

