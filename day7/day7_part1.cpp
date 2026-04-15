


// 1.Sort into different vectors (one pair, two pair etc.) in pairs of string_view and int
// 2.For every vector, starting from one pair and up to Five of a kind, sort them from best to worst. rank = 1
// iterate over them and add the bid times rank to sum (long long) and rank++.

#include "../common.h"
#include <math.h>


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

int main(int argc, char **argv) {
  
  return 0;
}