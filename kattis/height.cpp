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

enum {
      VISITED = 1,
      UNVISITED  =-1
};

int R = -1, C = -1;

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

////////////////////////////////////////////////////////////////////////////////

int main(void) {
  auto testcases = -1, testcase = 1;
  std::cin >> testcases;

  while (std::cin >> testcase) {
    int arr[25], n = 20;
    for (auto i = 0; i < n; i++) {
      std::cin >> arr[i];
    }

    int i = 1, steps = 0;
    while (i < n) {
      int j = i;
      while (j > 0 and arr[j - 1] > arr[j]) {
        std::swap(arr[j], arr[j - 1]);
        j -= 1;
        steps += 1;
      }
      i += 1;
    }
    std::cout << testcase << " " << steps << std::endl;
  }
  return 0;
}
