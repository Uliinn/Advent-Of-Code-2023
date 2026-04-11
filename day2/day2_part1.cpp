#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

constexpr int REDS = 12;
constexpr int GREENS = 13;
constexpr int BLUES = 14;

int main(int argc, char **argv) {
    std::ifstream file("../day2/day2_input.txt");

    if(!file.is_open()) {
      std::cerr << "Error opening file.\n";
      return 1;
    }

    int sum = 0;
    string line;
    string _;
    while(std::getline(file, line)) { // each game
      stringstream game_stream(line);
      int id;
      game_stream >> _ >> id >> _;
      string round;
      while (getline(game_stream, round, ';')) {
        stringstream round_stream(round);
        string cubes, color;
        int num;
        while (getline(round_stream, cubes, ',')) {
          stringstream cubes_stream(cubes);
          cubes_stream >> num >> color;

          if (color == "red" && num > REDS) {
            goto end;
          } else if (color == "green" && num > GREENS) {
            goto end;
          } else if (color == "blue" && num > BLUES) {
            goto end;
          }
        }
      }

      sum += id;
      end:
      ;
    }
    cout << sum << '\n';
  }