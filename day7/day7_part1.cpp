#include "../common.h"
#include <algorithm>

struct Player {
  std::string_view card;
  int bid;
};

int symbol_to_int(const char symbol) {
  switch (symbol)
  {
  case 'A':
    return 14;
    break;
  case 'K':
    return 13;
    break;
  case 'Q':
    return 12;
    break;
  case 'J':
    return 11;
    break;
  case 'T':
    return 10;
    break;
  
  default:
    return symbol - '0';
  }
}

bool sortingFunc(Player a, Player b) {

  for (int i = 0; i < 5; i++) {
    int as = symbol_to_int(a.card[i]);
    int bs = symbol_to_int(b.card[i]);
    if (as == bs)
      continue;
    return as < bs;
  }
  return true;
}



std::vector<int> count(std::string_view s) {
  std::vector<int> result;
  std::vector<char> seen;
  
  for (char c : s) {
    auto i = std::find(seen.begin(), seen.end(), c);
    if (i != seen.end()) { // in
      result[i - seen.begin()]++;
    } else {
      seen.push_back(c);
      result.push_back(1);
    }
  }
  std::sort(result.begin(), result.end(), [](int a, int b)
            { return a > b; });

  return result;
}


int main(int argc, char **argv) {

  Timer timer;
  timer.begin();
  std::ifstream file("../day7/day7_input.txt");
  std::vector<std::string> lines = readlines(file);

  std::vector<Player> high, one, two, three, full, four, five;

  for (const std::string& s :lines) {
    std::vector<std::string_view> line = split(s);
    Player player = {
        line[0],
        parse_int(line[1])
    };
    std::vector<int> c = count(line[0]);
    
    if (c[0] == 5) {
      five.push_back(player);
    } else if (c[0] == 4) {
      four.push_back(player);
    } else if (c[0] == 3 && c[1] == 2) {
      full.push_back(player);
    } else if (c[0] == 3) {
      three.push_back(player);
    } else if (c[0] == 2 && c[1] == 2) {
      two.push_back(player);
    } else if (c[0] == 2) {
      one.push_back(player); 
    } else {
      high.push_back(player);
    }
  }

  long long sum = 0;

  int rank = 1;


  std::vector<std::vector<Player>> all = {high, one, two, three, full, four, five};

  for (std::vector<Player>& v : all) {
    std::sort(v.begin(), v.end(), sortingFunc);

    for (Player p : v) {
      sum += p.bid * rank;
      rank += 1;
    }
  }

  std::cout << sum << '\n';
  timer.stop();
  return 0;
}