#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
      if (c == '*') {
        std::vector<int> values;
        std::vector<std::pair<int, int>> seen;

        for (auto d : dirs) {
          int dx = d.first;
          int dy = d.second;
          int nx = x + dx;
          int ny = y + dy;

          if (ny < 0 || ny >= HEIGHT) continue;
          if (nx < 0 || nx >= WIDTH)  continue;


          if (isdigit(grid[ny][nx])) {
            int start = nx;
            while (start > 0 && isdigit(grid[ny][start - 1]))
              start--;

            if (std::find(seen.begin(), seen.end(), std::make_pair(start, ny)) != seen.end())
              continue;
            seen.push_back({start, ny});
            
            int num = 0;
            int s = start;
            
            while( s < WIDTH && isdigit(grid[ny][s])) {
              num = num * 10 + (grid[ny][s] - '0');
              s++;
            }
            values.push_back(num);
          }
        }

        if (values.size() == 2)
          sum += values[0] * values[1];
      }
      
      
    }
  }
  std::cout << sum << '\n';
  return 0;
}