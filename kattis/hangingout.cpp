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
  int limit, x;
  std::cin >> limit >> x;

  std::string direction;
  int people, denied = 0, current = 0;
  for (auto i = 0; i < x; i++) {
    std::cin >> direction >> people;
    if (direction == "leave") {
      current = current - people;
    } else if (people + current > limit) {
        denied += 1;
    } else {
      current = current + people;
    }
  }
  std::cout << denied << std::endl;
  return 0;
}
