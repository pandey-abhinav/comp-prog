#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define DEBUG(x) do {std::cerr << x << std::endl;; } while(0)
#define DEBUG2(x, y) do {std::cerr << x << " " << y << std::endl;; } while(0)

#define MAX_R 505
#define MAX_C 505

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

enum {
      VISITED = 1,
      UNVISITED  =-1
};

int state[MAX_R][MAX_C];
int height[MAX_R][MAX_C];
int R, C;

int dfs(int r, int c, int depth) {
  state[r][c] = VISITED;

  std::cout << r << " " << c << " " << depth << std::endl;

  int result = 0;
  bool downstep = false;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr >= R or nc >= C or nr < 0 or nc < 0) {
      continue;
    }
    if (height[nr][nc] <= height[r][c] and state[nr][nc] == UNVISITED) {
      result += dfs(nr, nc, depth + 1);
      if (height[nr][nc] < height[r][c]) {
        downstep = true;
      }
    }
  }
  if (downstep == true) {
    return result;
  }
  std::cout << "downstep if false for " << r << " " << c << " " << depth << std::endl;
  return 1 + result;
}


int main(void) {
  while (std::cin >> C >> R) {

    std::memset(state, UNVISITED, MAX_R * MAX_C * sizeof(int));

    // std::cout << R  << " " << C << std::endl;
    int top_height = -1, top_i = -1, top_j = -1;

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        std::cin >> height[i][j];
        if (height[i][j] > top_height) {
          top_height = height[i][j];
          top_i = i;
          top_j = j;
        }
      }
    }

    int result = 0;

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (state[i][j] == UNVISITED) {
          result += dfs(i, j, 0);
        }
      }
    }

    std::cout << result << std::endl;

  }

  return 0;
}
