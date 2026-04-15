#include <iostream>
#include <fstream>
#include "../common.h"
#include <set>
#include <charconv>


struct DstRange {
  long long dststart;
  long long srcstart;
  long long len;
};

struct Range {
  long long start;
  long long len;
};

int main(int argc, char **argv) {
  Timer timer;
  timer.begin();
  std::ifstream file("../day5/day5_input.txt");

  std::vector<std::string> lines = readlines(file);

  std::vector<Range> ranges;

  std::vector<std::string_view> seeds_line = split(lines[0]);

  for (int i = 1; i < seeds_line.size(); i += 2) {

    Range range = {
        parse_ll(seeds_line[i]),
        parse_ll(seeds_line[i + 1])};
    
    ranges.push_back(range);
    }

  int line_idx = 3;
  std::vector<std::string_view> rangev;
  while ( line_idx < lines.size()) {
    std::vector<Range> next_ranges;

    while(line_idx < lines.size() && lines[line_idx] != "" ) {
      rangev = split(lines[line_idx]);

      DstRange range = {
        parse_ll(rangev[0]),
        parse_ll(rangev[1]),
        parse_ll(rangev[2])
      };
      Range val, r1, r2;
      bool splitted;
      std::vector<Range> new_ranges;

      for (auto val : ranges) {

        long long val_end = val.start + val.len;
        long long map_start = range.srcstart;
        long long map_end = range.srcstart + range.len;

        // No overlap
        if (val_end <= map_start || val.start >= map_end) {
            new_ranges.push_back(val);
            continue;
        }

          // Left part (unmapped)
        if (val.start < map_start) {
            new_ranges.push_back({
                val.start,
                map_start - val.start
            });
        }

        long long overlap_start = std::max(val.start, map_start);
        long long overlap_end = std::min(val_end, map_end);

        next_ranges.push_back({
            range.dststart + (overlap_start - map_start),
            overlap_end - overlap_start
        });

          // Right part (unmapped)
        if (val_end > map_end) {
          new_ranges.push_back({
          map_end,
          val_end - map_end
          });
        }
      }
      ranges = std::move(new_ranges);
            line_idx++;
    }

    for (Range r : ranges) {
      next_ranges.push_back(r);
    }

    ranges = std::move(next_ranges);
    line_idx += 2;
  }
  long long min = ranges[0].start;

  for (int i = 1; i < ranges.size(); i++) {
    if (ranges[i].start < min)
      min = ranges[i].start;
  }
  std::cout << min << '\n';
  timer.stop();
  return 0;
  }