#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define DEBUG(x) do {std::cerr << x << std::endl;; } while(0)
#define DEBUG2(x, y) do {std::cerr << x << " " << y << std::endl;; } while(0)

#define MAX_M 1010

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

enum {
      VISITED = 1,
      UNVISITED  =-1
};

int state[MAX_M];
std::vector<std::vector<int> >AL;

void dfs(int u) {
  state[u] = VISITED;

  for (auto v : AL[u]) {
    if (state[v] == UNVISITED) {
      dfs(v);
    }
  }

}


int main(void) {

  int n;
  std::cin >> n;

  for (int t = 0; t < n; t++) {

    int m, r;
    std::cin >> m >> r;

    AL.clear();
    AL.resize(m);
    int u, v;
    for (int i = 0; i < r; i++) {
      std::cin >> u >> v;
      AL[u].push_back(v);
      AL[v].push_back(u);
    }

    int result = -1;
    std::memset(state, UNVISITED, m * sizeof(int));

    for (int u = 0; u < m; u++) {
      if (state[u] == UNVISITED) {
        dfs(u);
        result += 1;
      }
    }
    std::cout << result << std::endl;
  }
  return 0;
}
