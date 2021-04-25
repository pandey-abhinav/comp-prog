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

int main(void) {
  auto testcase = 1;
  int W, L;

  while (std::cin >>  W >>  L) {
    if (W == 0 and L == 0) {
      break;
    }
    std::vector<std::string>house;
    std::cin.ignore();
    for (auto i = 0; i < L; i++) {
      std::string line;
      std::getline(std::cin, line);
      house.push_back(line);
    }

    int dr = 0, dc = 0, r = -1, c = -1;

    for (auto j = 0; j < W; j++) {
      if (house[0][j] == '*') {
        dr = 1;
        dc = 0;
        r = 0;
        c = j;
      }
    }

    for (auto j = 0; j < W; j++) {
      if (house[L - 1][j] == '*') {
        dr = -1;
        dc = 0;
        r = L - 1;
        c = j;
      }
    }

    for (auto i = 0; i < L; i++) {
      if (house[i][0] == '*') {
        dr = 0;
        dc = 1;
        r = i;
        c = 0;
      }
    }

    for (auto i = 0; i < L; i++) {
      if (house[i][W - 1] == '*') {
        dr = 0;
        dc = -1;
        r = i;
        c = W - 1;
      }
    }

    while (house[r][c] != 'x') {
      int nr = r + dr, nc = c + dc;
      if (house[nr][nc] == '\\') {
        std::swap(dr, dc);
      }
      if (house[nr][nc] == '/') {
        std::swap(dr, dc);
        dr = dr * -1;
        dc = dc * -1;
      }
      r = nr;
      c = nc;
    }
    house[r][c] = '&';

    std::cout << "HOUSE " << testcase << std::endl;
    testcase += 1;
    for (int i = 0; i < L; i++) {
      std::cout << house[i] << std::endl;
    }
  }
  return 0;
}
