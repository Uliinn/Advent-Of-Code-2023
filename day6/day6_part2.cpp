#include "../common.h"


int main(int argc, char **argv) {

  int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

  Timer timer;
  
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
  timer.begin();

  int possibilities = 0;

    for (int s = 1; s < real_time; s++) {

      if ((real_time - s) * s > real_distance ) {
        possibilities++;
      }
  }
   
  std::cout << possibilities << '\n';
  timer.stop();
  return 0;
  }