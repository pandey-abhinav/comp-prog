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
  auto testcases = -1;
  std::cin >> testcases;

  for (auto testcase = 0; testcase < testcases; testcase++) {
    auto n = -1, votes = -1, max_votes = -1, total_votes = 0, winner = -1;

    std::cin >> n;

    for (auto i = 0; i < n; i++) {
      std::cin >> votes;
      if (votes > max_votes) {
        max_votes = votes;
        winner = i + 1;
      } else if (votes == max_votes) {
        winner = -1;
      }
      total_votes += votes;
    }

    if (winner == -1) {
      std::cout << "no winner" << std::endl;
    } else if (max_votes > total_votes / 2) {
      std::cout << "majority winner " << winner << std::endl;
    } else {
      std::cout << "minority winner " << winner << std::endl;
    }
  }

  return 0;
}
