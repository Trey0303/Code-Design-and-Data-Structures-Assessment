#include <iostream>
#include "Hashing.h"

int main()
{
    //negative numbers wont work with this type(uint32_t)
    uint32_t firstHash = hash<uint32_t>(1);
    uint32_t secondHash = hash<uint32_t>(2);
    uint32_t thirdHash = hash<uint32_t>(4);

    //size_t
    uint32_t fifthHash = hash<size_t>(1);
    uint32_t sixthHash = hash<size_t>(2);
    uint32_t seventhHash = hash<size_t>(4);

    //int
    uint32_t eighthHash = hash<int>(1);
    uint32_t ninthHash = hash<int>(2);
    uint32_t tenthHash = hash<int>(4);

    //char
    uint32_t eleventhHash = hash<char>(1);
    uint32_t twelfthHash = hash<char>(2);
    uint32_t thirteenthHash = hash<char>(4);

    //bool
    uint32_t fourteenthHash = hash<bool>(false);
    uint32_t fifteenthHash = hash<bool>(true);
    //uint32_t sixteenthHash = hash<bool>();

    return 0;
}

