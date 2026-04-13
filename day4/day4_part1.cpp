#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>


int main(int argc, char **argv) {
    std::ifstream file("../day4/day4_input.txt");

    if(!file.is_open()) {
      std::cerr << "Error opening file.\n";
      return 1;
    }

    std::string line;
    int sum = 0;
    while(std::getline(file,line)) {

      std::string rest = line.substr(line.find(':') + 1);
      
      std::stringstream ss(rest);
      std::string left, right;
      std::getline(ss, left, '|');
      std::getline(ss, right);

      std::unordered_set<int> winning;
      std::istringstream ls(left);
      int num;
      while (ls >> num) {
        winning.insert(num);
      }

      int matching = 0;
      std::istringstream rs(right);
      while (rs >> num) {
        if (winning.count(num) == 1) {
          matching++;
        }
      }

      if (matching != 0) {
        sum += 1 << (matching - 1);
      }
    }

    std::cout << sum << '\n';
    return 0;
  }