#include <iostream>
#include <fstream>
#include <string>
#include <vector>

constexpr int WIDTH = 140;
constexpr int HEIGHT = 140;

int main(int argc, char **argv) {
  std::ifstream file("../day3/day3_input.txt");

  if(!file.is_open()) {
      std::cerr << "Error opening file.\n";
      return 1;
  }

  int sum = 0;
  char grid[HEIGHT][WIDTH] = {0};
  std::string line;
  int x = 0, y = 0;

  while(std::getline(file,line)) {
    x = 0;
    for(char c: line) {
      grid[y][x] = c;
      x++;
    }
    y++;
  }

  std::vector<std::pair<int,int>> dirs = {
    {-1, 0}, {1, 0},   
    {0, -1}, {0, 1},   
    {-1,-1}, {-1, 1}, 
    {1, -1}, {1, 1}
};

  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      char c = grid[y][x];
      if (isdigit(c)) {
        std::vector<int> v;
        bool symbol_nearby = false;

        while (isdigit(c) && x < WIDTH) {
          v.push_back(c - '0');

          for (auto d : dirs) {
            int dx = d.first, dy = d.second;
            int nx = x + dx;
            int ny = y + dy;
            
            if (ny < 0 || ny >= HEIGHT) continue;
            if (nx < 0 || nx >= WIDTH) continue;

            char neighbour = grid[ny][nx];

            if (!isdigit(neighbour) && neighbour != '.')
              symbol_nearby = true;
          }

          x++;
          c = grid[y][x];
        }

        if (symbol_nearby) {
          int magnitude = 1;
          while (!v.empty()) {
            int val = v.back();
            v.pop_back();
            sum += val * magnitude;
            magnitude *= 10;
          }
        }

      }


    }
  }
  std::cout << sum << '\n';
  return 0;
}