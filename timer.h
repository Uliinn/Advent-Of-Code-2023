#pragma once
#include <chrono>
#include <cstdio>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    
    void begin() {
        start = std::chrono::high_resolution_clock::now();
    }
    
    void stop() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        printf("%.3f us\n", duration.count() / 1000.0);
    }
};