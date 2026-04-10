#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    std::ifstream file("../day1/day1_input.txt");

    if(!file.is_open())
    {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int sum = 0;
    std::string line;
    std::string substrings[] = {"zero","one", "two", "three", "four", "five",
                                "six", "seven", "eight", "nine"};
    int substrings_size = sizeof(substrings) / sizeof(substrings[0]);
    while(std::getline(file, line)) {
      // first number
      int string_val = -1;

      int first_string_idx = line.size();
      int first_digit_idx = -1;
      
      for (int i = 0; i < substrings_size; i++) {
        std::string substring = substrings[i];
        size_t pos = line.find(substring);
        if (pos != std::string::npos && (int)pos < first_string_idx) {
          first_string_idx = pos;
          string_val = i;
        }
      }

      for (int i = 0; i < line.size(); i++) {
        if (std::isdigit(line[i])) {
          first_digit_idx = i;
          break;
        }
      }

      int first;
      if (first_digit_idx < first_string_idx && first_digit_idx != -1) {
        first = line[first_digit_idx] - '0';
      } else {
        first = string_val;
      }

      // last number
      int last_string_idx = -1;
      int last_digit_idx = -1;

      for (int i = 0; i < substrings_size; i++) {
        std::string substring = substrings[i];
        size_t pos = line.rfind(substring);
        if (pos != std::string::npos && (int)pos > last_string_idx) {
          last_string_idx = pos;
          string_val = i;
        }
      }
      
      for (int i = line.size() - 1; i >= 0; i--) {
        if (std::isdigit(line[i])) {
          last_digit_idx = i;
          break;
        }
      }

      int last;

      if (last_digit_idx > last_string_idx && last_digit_idx != -1) {
        last = line[last_digit_idx] - '0';
      } else {
        last = string_val;
      }
      // convert to numbers
      
      sum += first * 10 + last;
    }

    printf("%d\n", sum);

    return 0;
}