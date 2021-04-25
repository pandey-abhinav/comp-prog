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
  int n = -1;
  while (std::cin >> n) {
    int total_at_bat = 0, base = 0;
    double total_base = 0;
    for (int i = 0; i < n; i++) {
      std::scanf("%d", &base);
      if (base != -1) {
        total_base += base;
        total_at_bat += 1;
      }
    }
    printf("%lf\n", total_base / total_at_bat);
  }
  return 0;
}
