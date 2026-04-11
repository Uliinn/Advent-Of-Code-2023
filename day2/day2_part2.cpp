#include <iostream>
#include <fstream>
#include <sstream>
#include "../timer.h"
using namespace std;



int main(int argc, char **argv) {
  Timer timer;
  timer.begin();
  
  std::ifstream file("../day2/day2_input.txt");

  if (!file.is_open())
  {
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
      int REDS = 0;
      int GREENS = 0;
      int BLUES = 0;
      while (getline(game_stream, round, ';')) {
        stringstream round_stream(round);
        string cubes, color;
        int num;
        while (getline(round_stream, cubes, ',')) {
          stringstream cubes_stream(cubes);
          cubes_stream >> num >> color;

          if (color == "red" && num > REDS) {
            REDS = num;
          } else if (color == "green" && num > GREENS) {
            GREENS = num;
          } else if (color == "blue" && num > BLUES) {
            BLUES = num;
          }
        }
      }

      sum += REDS * GREENS * BLUES;
      
    }
    cout << sum << '\n';
    timer.stop();
  }