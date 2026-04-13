#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>

constexpr int NUM_OF_CARDS = 192;

int main(int argc, char **argv) {
    std::ifstream file("../day4/day4_input.txt");

    if(!file.is_open()) {
      std::cerr << "Error opening file.\n";
      return 1;
    }

    int cards[NUM_OF_CARDS];
    for (int i = 0; i < NUM_OF_CARDS; i++) { // One original copy of every card
      cards[i] = 1;
    }
    
    std::string line;
    std::string card;
    
    while(std::getline(file,line)) {

      std::string before = line.substr(0, line.find(':'));;
      std::stringstream bf(before);
      int id;

      bf >> card >> id;

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
      int copies = cards[id - 1];
      while (matching != 0 && id < NUM_OF_CARDS) {
        cards[id++] += copies;
        matching--;
      }
    }
    int sum = 0;
    for (int i = 0; i < NUM_OF_CARDS; i++) {
      sum += cards[i];
    }
    
    std::cout << sum << '\n';
    return 0;
  }