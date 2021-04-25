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

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};


////////////////////////////////////////////////////////////////////////////////

int main(void) {
  int arr[10];
  for (int i = 0; i < 5; i++) {
    std::cin >> arr[i];
  }

  bool check = true;
  while (check == true) {
    check = false;
    for (int i = 0; i < 4; i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);

        std::cout << arr[0];
        for (auto i = 1; i < 5; i++) std::cout << " " << arr[i];
        std::cout << std::endl;

        check = true;
      }
    }
  }
  return 0;
}
