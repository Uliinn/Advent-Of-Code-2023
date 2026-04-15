#include <iostream>
#include <fstream>
#include "../common.h"
#include <set>
#include <charconv>


struct Range {
  long long dststart;
  long long srcstart;
  long long len;
};

int main(int argc, char **argv) {
  Timer timer;
  timer.begin();
  std::ifstream file("../day5/day5_input.txt");

  std::vector<std::string> lines = readlines(file);

  std::vector<long long> nums;

  std::vector<std::string_view> seeds_line = split(lines[0]);

  for (int i = 1; i < seeds_line.size(); i++) {
    nums.push_back(parse_ll(seeds_line[i]));
  }

  int line_idx = 3;
  std::vector<std::string_view> rangev;
  while ( line_idx < lines.size()) {
    std::vector<long long> next_nums;

    while(line_idx < lines.size() && lines[line_idx] != "" ) {
      rangev = split(lines[line_idx]);

      Range range = {
        parse_ll(rangev[0]),
        parse_ll(rangev[1]),
        parse_ll(rangev[2])
      };

      for (int i = 0; i < nums.size(); i++) {
        long long val = nums[i];
        if (val >= range.srcstart && val < range.srcstart + range.len) {
          next_nums.push_back(range.dststart + (val - range.srcstart));
          nums[i] = nums.back();
          nums.pop_back();
          i--;
        }
      }
      line_idx++;
      }
    // For the ones that didn't fit in a range:

    for (long long v : nums) {
      next_nums.push_back(v);
    }

    nums = std::move(next_nums);
    line_idx += 2;
  }
  long long min = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < min)
      min = nums[i];
  }
  std::cout << min << '\n';
  timer.stop();
  return 0;
  }