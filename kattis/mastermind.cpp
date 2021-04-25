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
  std::string C, G;
  int n;

  int freqC[30], freqG[30];

  while (std::cin >> n >> C >> G) {
    int r = 0, s = 0;
    memset(freqC, 0, sizeof(int) * 30);
    memset(freqG, 0, sizeof(int) * 30);
    for (int i = 0; i < n; i++) {
      if (C[i] == G[i]) {
        r += 1;
      } else {
        freqC[C[i] - 65] += 1;
        freqG[G[i] - 65] += 1;
      }
    }
    // for (int i = 0; i < 30; i++) {
    //   std::cout << freqC[i] << " ";
    // }
    // std::cout << std::endl;
    // for (int i = 0; i < 30; i++) {
    //   std::cout << freqG[i] << " ";
    // }
    // std::cout << std::endl;

    for (int i = 0; i < 30; i++) {
      s += std::min(freqC[i], freqG[i]);
    }

    std::cout << r << " " << s << std::endl;

  }
  return 0;
}
