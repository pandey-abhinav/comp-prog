// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// DEBUG STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<typename ttype> void debug(std::vector<ttype> &vec) {
  std::cerr << "DEBUG LOG :: vector [";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cerr << *it << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void debug(std::map<ttype, ttype> &m) {
  std::cerr << "DEBUG LOG :: map [";
 for (auto it = m.begin(); it != m.end(); it++) {
    std::cerr << it->first << "=" << it->second << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void debug(ttype val) {
  std::cerr << "DEBUG LOG :: object [" << val << "]" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// GRAPH STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
enum {
      VISITED = 1,
      UNVISITED  = 0
};

int status[1100][1100];
char grid[1100][1100];

int R = -1, C = -1;

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void exploreSea(int r, int c) {
  status[r][c] = 1;
  for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr >= 0 and nc >= 0 and nr < R and nc < C
        and status[nr][nc] == UNVISITED and grid[nr][nc] == '0') {
      exploreSea(nr, nc);
    }
  }
}

int getCoastLength(int r, int c, int coast) {
  // std::cout << "r = " << r << ", c = " << c << ", coast = " << coast << std::endl;
  status[r][c] = 2;
  for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr >= R or nc >= C or nr < 0 or nc < 0) {
      coast += 1;
    } else {
      if (grid[nr][nc] == '0' and status[nr][nc] == 1) {
        coast += 1;
      }
      if (grid[nr][nc] == '1' and status[nr][nc] == UNVISITED) { // if unvisited land
        coast += getCoastLength(nr, nc, 0);
      }
    }
  }
  return coast;
}

// void printStatus() {
//   for (int i = 0; i < R; i++) {
//     for (int j = 0; j < C; j++) {
//       std::cout << status[i][j];
//     }
//     std::cout << std::endl;
//   }
//   std::cout << std::endl;
// }

int main(void) {
  std::cin >> R >> C;
  for (int i = 0; i < R; i++) {
    std::cin >> grid[i];
  }

  // for (int i = 0; i < R; i++) {
  //   std::cout << grid[i] << std::endl;
  // }
  // std::cout << std::endl;


  for (int i = 0; i< R; i++) {
    for (int j = 0; j < C; j++) {
      status[i][j] = UNVISITED;
    }
  }

  for (int j = 0; j < C; j++) {
    if (grid[0][j] == '0' and status[0][j] == UNVISITED) {
      exploreSea(0, j);
    }
    if (grid[R - 1][j] == '0' and status[R - 1][j] == UNVISITED) {
      exploreSea(R - 1, j);
    }
  }

  for (int i = 0; i < R; i++) {
    if (grid[i][0] == '0' and status[i][0] == UNVISITED) {
      exploreSea(i, 0);
    }
    if (grid[i][C - 1] == '0' and status[i][C - 1] == UNVISITED) {
      exploreSea(i, C - 1);
    }
  }

  int coast = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (grid[i][j] == '1'  and status[i][j] == UNVISITED) {
        coast += getCoastLength(i, j, 0);
        // std::cout << coast << std::endl;
      }
    }
  }
  // printStatus();

  std::cout << coast << std::endl;

  return 0;
}
