#pragma once

#include <chrono>

class stopwatch {

	std::chrono::milliseconds totalMilliseconds;
	std::chrono::high_resolution_clock::time_point lastStartTime;


public:
	stopwatch();

	void start();

	void stop();

	std::chrono::milliseconds elapsed();

	double millisecondCount();

	double secondCount();

	void reset();

};