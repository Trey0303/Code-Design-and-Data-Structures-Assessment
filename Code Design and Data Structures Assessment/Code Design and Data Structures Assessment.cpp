// Code Design and Data Structures Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stopwatch.h"

#include <thread>
#include <chrono>

void bubbleSort(int* numbers, size_t numberLength) {
    for (size_t i = 0; i < numberLength; ++i) {
        bool swapped = false;
        for (size_t j = 1; j < numberLength; ++j) {
            if (numbers[j - 1] > numbers[j]) {
                int temp = numbers[j - 1];
                numbers[j - 1] = numbers[j];
                numbers[j] = temp;

                swapped = true;
            }
        }
    }
}


int main()
{
    stopwatch demoTimer;

    int numbersLength = 100000;
    int *numbers = new int[numbersLength];

    for (size_t i = 0; i < numbersLength; ++i) {
        numbers[i] = i;
    }

    std::cout << "number generation done" << std::endl;

    demoTimer.start();

    bubbleSort(numbers, numbersLength);

    demoTimer.stop();

    /*using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);*/

    std::cout << demoTimer.millisecondCount() << std::endl;
    std::cout << demoTimer.secondCount() << std::endl;

    return 0;
}


