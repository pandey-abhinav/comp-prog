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
  std::string N, M;

  while (std::cin >> N >> M) {
    int n = N.length(), m = M.length();

    // std::cout << "N = " << N << ", M = " << M << std::endl;

    if (n >= m) {
      int k = m - 1;
      for (int i = N.length() - 1; i >= 0 and k > 0; i--) {
        if (N[i] != '0') break;
        k -= 1;
      }
      // std::cout << "k = " << k << std::endl;
      if (k == 0) {
        std::cout  << N.substr(0, n - m + 1) << std::endl;
      } else {
        std::cout  << N.substr(0, n - m + 1) << "." << N.substr(n - m + 1, k)  << std::endl;
      }
    } else {
      std::cout << "0.";
      for (int i = 0; i < m - n - 1; i++) {
        std::cout << "0";
      }
      std::cout << N << std::endl;
    }
  }
  return 0;
}
