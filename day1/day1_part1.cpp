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
    while(std::getline(file, line)) {
      int first_idx = -1;
      int last_idx = -1;
      for (int i = 0; i < line.size(); i++) {
        if (std::isdigit(line[i]) && first_idx == -1) {
          first_idx = i;
          break;
        }
      }
      for (int i = line.size() - 1; i >= 0; i--)
      {
        if (std::isdigit(line[i]) && last_idx == -1) {
          last_idx = i;
          break;
        }
      }

      // convert to numbers
      int first = line[first_idx] - '0';
      int last = line[last_idx] - '0';

      sum += first * 10 + last;
    }

    printf("%d\n", sum);

    return 0;
}