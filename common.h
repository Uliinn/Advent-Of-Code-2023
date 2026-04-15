#pragma once
#include <chrono>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <string_view>
#include <fstream>
#include <iostream>
#include <charconv>

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

std::vector<std::string_view> split(std::string_view s, char delim);
std::vector<std::string_view> split(std::string_view s);
std::vector<std::string> readlines(std::ifstream &file);

int parse_int(std::string_view sv);
long long parse_ll(std::string_view sv);