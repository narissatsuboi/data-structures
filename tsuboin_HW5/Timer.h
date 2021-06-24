// Narissa Tsuboi
// Timer.h
// Specification file of Timer class used to measure the runtime of a function.


#ifndef CPP_TIMER_H
#define CPP_TIMER_H

#include <iostream>
#include <string>
#include <sys/time.h>

class Timer {
public:
    Timer(std::string name) {
        start = timeInMillis();
        this->name = name;
    }

    ~Timer() {
        time_t end = timeInMillis();
        std::cerr << "Duration of " << name << ": " << end - start
        << " milliseconds" << std::endl;
    }

private:
    time_t start;
    std::string name;

    time_t timeInMillis() {
        struct timeval time_now{};
        gettimeofday(&time_now, nullptr);
        return (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    }
};
#endif //CPP_TIMER_H
