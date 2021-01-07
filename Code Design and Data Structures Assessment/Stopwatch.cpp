#include "Stopwatch.h"

stopwatch::stopwatch() {
	totalMilliseconds = std::chrono::milliseconds();

}

void stopwatch::start() {
	lastStartTime = std::chrono::high_resolution_clock::now();

}

void stopwatch::stop() {
	auto diff = std::chrono::high_resolution_clock::now() - lastStartTime;
	totalMilliseconds += std::chrono::duration_cast<std::chrono::milliseconds>(diff);

}

double stopwatch::millisecondCount() {
	return totalMilliseconds.count();
}

double stopwatch::secondCount() {
	return std::chrono::duration_cast<std::chrono::seconds>(totalMilliseconds).count();

}

void stopwatch::reset() {
	totalMilliseconds = std::chrono::milliseconds();
}