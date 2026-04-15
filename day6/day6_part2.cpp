#include "../common.h"
#include <math.h>


int main(int argc, char **argv) {
  
  

  Timer timer;
  timer.begin();
  
  int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

  std::ifstream file("../day6/day6_input.txt");

  std::vector<std::string> lines = readlines(file);

  auto times = split(lines[0]);
  long long real_time = 0;
  for (int i = 1; i < times.size(); i++) {
    auto time = times[i];
    int len = time.size();
    real_time *= pow10[len];
    real_time += parse_ll(time);
  }

  auto distances = split(lines[1]);
  long long real_distance = 0;
  for (int i = 1; i < distances.size(); i++) {
    auto dist = distances[i];
    int len = dist.size();
    real_distance *= pow10[len];
    real_distance += parse_ll(dist);
  }
  

  // 2 roots, and in between them.
  // Old loop had (time - s) * s > distance -> time*s - s^2 > distance which it is between 2 roots
  // s^2 - time*s + distance = 0
  // s = time/2 +- sqrt(time^2/4 - distance)
  // root1 = time/2 - sqrt(time^2/4 - distance)
  // root2 = time/2 + sqrt(time^2/4 - distance)
  // All in betweeen is root2 - root1
  // root1 = A - B
  // root2 = A + B
  // Then interval is A + B - (A - B) = 2B
  // If it was A = 1 and B = 1 then the range would be from [0,2] so 3 points, 2B is only 2, then + 1 for offset

  long long B = std::sqrt((real_time * real_time) / 4 - real_distance);

  std::cout << 2 * B + 1 << '\n';
  timer.stop();
  return 0;
  }