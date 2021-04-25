#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MAX_N 2000005

#define DEBUG(x) do {std::cerr << x << std::endl;; } while(0)

enum {
      VISITED = 1,
      UNVISITED  =-1
};

int state[MAX_N];

std::vector<std::vector<int> >AL;

void dfs(int u) {

  state[u] = VISITED;

  for (auto &v : AL[u]) {
    if (state[v] == UNVISITED) {
      dfs(v);
    }
  }
}


int main(void) {
  int n, m;
  std::cin >> n >> m;

  AL.resize(n + 1);


  int u, v;
  for (int i = 1; i <= m; i++) {
    std::cin >> u >> v;
    AL[u].push_back(v);
    AL[v].push_back(u);
  }

  std::memset(state, UNVISITED, MAX_N * sizeof(int));

  dfs(1);

  int result = 0;

  for (int i = 1; i <= n; i++) {
    if (state[i] == UNVISITED) {
      result = -1;
    }
  }
  if (result == -1) {
    for (int i = 1; i <= n; i++) {
      if (state[i] == UNVISITED) {
        std::cout << i << std::endl;
      }
    }
  } else if (result == 0) {
    std::cout << "Connected" << std::endl;
  }
  return 0;
}
