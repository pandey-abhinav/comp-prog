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

int dr[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dc[] = {2, -2, 2, -2, 1, -1, 1, -1};
int R = 5, C = 5;

bool attacks(std::vector<std::string> &board, int r, int c) {
  for (auto k = 0; k < 8; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr >= R or nc >= C or nr < 0 or nc < 0) {
      continue;
    }
    if (board[nr][nc] == 'k') {
      return true;
    }
  }
  return false;
}

int main(void) {
  std::vector<std::string> board(5);
  for (auto i = 0; i < 5; i++) {
    std::cin >> board[i];
  }

  bool result = true;
  int count = 0;

  for (auto i = 0; i < 5 and result; i++) {
    for (auto j = 0; j < 5 and result; j++) {
      if(board[i][j] == 'k') {
        count += 1;
        if (attacks(board, i, j)) {
          result = false;
        }
      }
    }
  }
  if (result and count == 9) {
    std::cout << "valid" << std::endl;
  } else {
    std::cout << "invalid" << std::endl;
  }

  return 0;
}
