// C LIBRARIES
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

bool combo(char a, char b, char c) {
  auto check_r = false, check_b = false, check_l = false;

  if (a == 'R' or b == 'R' or c == 'R') check_r = true;
  if (a == 'B' or b == 'B' or c == 'B') check_b = true;
  if (a == 'L' or b == 'L' or c == 'L') check_l = true;

  if (check_r and check_b and check_l) return true;
  return false;
}

std::string defence_for(char attack) {
  switch(attack) {
  case 'R': return "S";
  case 'B': return "K";
  case 'L': return "H";
  }
  return "";
}

int main(void) {
  std::string attack;
  while (std::cin >> attack) {
    int a = 0, b = a + 2;
    std::string defence = "";

    while (a < attack.length()) {
      if (b < attack.length() and combo(attack[a], attack[a + 1], attack[a + 2])) {
          defence += "C";
          a += 3;
          b += 3;
      } else {
        defence += defence_for(attack[a]);
        a += 1;
        b += 1;
      }
    }
    std::cout << defence << std::endl;
  }
  return 0;
}
