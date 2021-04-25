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

enum {
      VISITED = 1,
      UNVISITED  =-1
};

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

////////////////////////////////////////////////////////////////////////////////

int main(void) {
  int R, C;
  bool check = false;
  while (std::cin >> R >> C) {
    if (R == 0 and C == 0) break;
    if (check == false) {
      check = true;
    } else {
      std::cout << std::endl;
    }

    std::vector<std::string> rows(R);

    for (int i = 0; i < R; i++) {
      std::cin >> rows[i];
    }

    std::vector<std::string> columns;

    for (int j = 0; j < C; j++) {
      std::string col(R, '*');
      for (int i = 0; i < R; i++) {
        col[i] = rows[i][j];
      }
      columns.push_back(col);
    }
    std::sort(columns.begin(), columns.end(), [](std::string a, std::string b) {
                                                for (auto i = 0; i < a.length(); i++) {
                                                  auto la = std::tolower(a[i]), lb = std::tolower(b[i]);
                                                  if (la == lb) continue;
                                                  return la < lb;
                                                }
                                                return false;
                                              });

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        std::cout << columns[j][i];
      }
      std::cout << std::endl;
    }

  }
  return 0;
}
