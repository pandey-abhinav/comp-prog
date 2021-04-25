// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(x) do {std::cerr << x << std::endl;; } while(0)

std::vector<int> p;

int main(void) {
  int n;

  std::cin >> n;
  p.clear();
  p.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }

  int d = 0;
  std::sort(p.begin(), p.end());

  for (int i = 0; i < p.size(); i++) {
    if (i + 2 < p.size()) {
      d += p[i + 2];
    }
  }
  std::cout << d << std::endl;



  return 0;
}
