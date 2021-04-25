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
  int h, w, n, m;
  int img[25][25], ker[25][25], res[25][25];

  std::cin >> h >> w >> n >> m;

  for (auto i = 0; i < h; i++) {
    for (auto j = 0; j < w;j ++) {
      std::cin >> img[i][j];
    }
  }

  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < m;j ++) {
      std::cin >> ker[i][j];
    }
  }

  // row flip
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < m; j++) {
      std::swap(ker[i][j], ker[n - 1 - i][j]);
    }
  }

  // col flip
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m / 2; j++) {
      std::swap(ker[i][j], ker[i][m - 1 - j]);
    }
  }

  for (int i = 0; i < h - n + 1; i++) {
    for (int j = 0; j < w - m + 1; j++) {
      int val = 0;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < m; l++) {
          val += ker[k][l] * img[i + k][j + l];
        }
      }
      res[i][j] = val;
    }
  }

  for (int i = 0; i < h - n + 1; i++) {
    for (int j = 0; j < w - m + 1; j++) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }


  return 0;
}
