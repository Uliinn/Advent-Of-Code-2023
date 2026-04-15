#pragma once
#include <chrono>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    
    void begin() {
        start = std::chrono::high_resolution_clock::now();
    }
    
    void stop() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        printf("%lld us\n", duration.count());
    }
};

std::vector<std::string> split(const std::string &s, char delimiter);
std::vector<std::string> readlines(const std::string &filename);
