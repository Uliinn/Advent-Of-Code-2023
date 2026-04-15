#include "../common.h"


int main(int argc, char **argv) {
  Timer timer;
  timer.begin();
  std::ifstream file("../day6/day6_input.txt");

  std::vector<std::string> lines = readlines(file);

  auto times = split(lines[0]);
  auto distances = split(lines[1]);

  int answer = 1;

  for (int i = 1; i < times.size(); i++) {
    int time = parse_ll(times[i]);
    int distance = parse_ll(distances[i]);
    int possibilities = 0;
    for (int s = 1; s < time; s++) {

      if ((time - s) * s > distance ) {
        possibilities++;
      }
    }
    if (possibilities != 0) {
      answer *= possibilities;
    }
  }
  std::cout << answer << '\n';
  timer.stop();
  return 0;
  }