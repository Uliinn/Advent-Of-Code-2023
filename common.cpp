#include "common.h"
#include <string_view>


long long parse_ll(std::string_view sv) {
    long long result;
    std::from_chars(sv.data(), sv.data() + sv.size(), result);
    return result;
}

std::vector<std::string_view> split(std::string_view s, char delim) {
    std::vector<std::string_view> rv;
    size_t start = 0;
    size_t end;


    while((end = s.find(delim,start)) != std::string_view::npos) {
        if (start != end)
            rv.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    rv.push_back(s.substr(start));

    return rv;
}

std::vector<std::string_view> split(std::string_view s) {
    
    return split(s, ' ');
}

std::vector<std::string> readlines(std::ifstream& file) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(std::move(line));
    return lines;
}