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
  auto n = -1;
  while(std::cin >> n) {
    std::vector<int> A(n, -1), G;
    for (auto i = 0; i < n; i++) {
      std::cin >> A[i];
    }
    auto i = 0, j = 1;
    G.push_back(A[0]);
    while (j < n) {
      if (A[j] > G[i]) {
        G.push_back(A[j]);
        i += 1;
      }
      j += 1;
    }
    std::cout << G.size() << std::endl;
    std::cout << G[0];

    for (auto i = 1; i < G.size(); i++) {
      std::cout << " " << G[i];
    }
    std::cout << std::endl;
  }
  return 0;
}
