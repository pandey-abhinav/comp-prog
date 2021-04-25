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

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};


////////////////////////////////////////////////////////////////////////////////

int main(void) {
  int n, m;
  while (std::cin >> n >> m) {
    std::cin.ignore();
    std::vector<std::string> grid;
    std::vector<std::vector<int > >ring(n, std::vector<int>(m, -1));
    std::string line;
    for (auto  i = 0; i < n; i++) {
      getline(std::cin, line);
      grid.push_back(line);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '.') {
          ring[i][j] = 0;
        }
      }
    }

    int ri = 0;
    while (true) {
      ri += 1;
      bool check = false;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (ring[i][j] == -1) {
            check = true;
            for (int k = 0; k < 4; k++) {
              int nr = i + dr[k], nc = j + dc[k];
              if (nr >= n or nc >= m or nr < 0 or nc < 0) {
                ring[i][j] = ri;
                continue;
              }
              if (ring[nr][nc] == ri - 1) {
                ring[i][j] = ri;
              }
            }
          }
        }
      }
      if (check == false) break;
    }
    int w = 2;
    if (ri > 10) w = 3;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ring[i][j] == 0) {
          if (w == 2) std::cout << "..";
          else std::cout << "...";
        }
        else std::cout << std::setfill('.') << std::setw(w) << ring[i][j];
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
