#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005


////////////////////////////////////////////////////////////////////////////////

int value(char hand) {
  switch(hand) {
  case 'A': return 1;
  case '2': return 2;
  case '3': return 3;
  case '4': return 4;
  case '5': return 5;
  case '6': return 6;
  case '7': return 7;
  case '8': return 8;
  case '9': return 9;
  case 'T': return 10;
  case 'J': return 11;
  case 'Q': return 12;
  case 'K': return 13;
  default: return -1;
  }
}

int main(void) {
  std::string hand;
  std::vector<int> cards(15, 0);

  for (int i = 0; i < 5; i++) {
    std::cin >> hand;
    int idx = value(hand[0]);
    cards[idx] += 1;
  }

  int result = -1;
  for (int i = 0; i < 15; i++) {
    if (cards[i] > result) {
      result = cards[i];
    }
  }
  std::cout << result << std::endl;
  return 0;
}
