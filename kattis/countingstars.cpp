#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define DEBUG(x) do {std::cerr << x << std::endl;; } while(0)
#define DEBUG2(x, y) do {std::cerr << x << " " << y << std::endl;; } while(0)

#define MAX_M 1010

#define MAX_R 1010
#define MAX_C 1010

enum {
      VISITED = 1,
      UNVISITED  =-1
};

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};
std::vector<std::string> grid;
int state[MAX_R][MAX_C];
int R,C;


void dfs(int r, int c) {
  state[r][c] = VISITED;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr >= R or nc >= C or nr < 0 or nc < 0) continue;
    if (grid[nr][nc] == '-' and state[nr][nc] == UNVISITED) {
      dfs(nr, nc);
    }
  }
}

int main(void) {
  int t = 1;
  while(std::cin >> R >> C) {
    grid.clear();
    grid.resize(R);
    for (int i = 0; i < R; i++) {
      std::cin >> grid[i];
    }

    std::memset(state, UNVISITED, sizeof(state));
    int result = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (grid[i][j] == '-' and state[i][j] == UNVISITED) {
          result += 1;
          dfs(i, j);
        }
      }
    }
    std::cout << "Case " << t << ": " << result << std::endl;
    t += 1;
  }
  return 0;
}
