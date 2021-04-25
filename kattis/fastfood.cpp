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

bool can_claim_prize(std::vector<int> &cost, std::vector<int> &coach) {
  for (int i = 0; i < cost.size(); i++) {
    if (coach[cost[i] - 1] == 0) {
      return false;
    }
  }
  for (int i = 0; i < cost.size(); i++) {
    coach[cost[i] - 1] -= 1;
  }
  return true;
}

int main(void) {
  auto testcases = -1;
  std::cin >> testcases;

  for (auto testcase = 1; testcase <= testcases; testcase++) {
    auto p = -1, s = -1;

    std::cin >> p >> s;

    std::vector<std::vector<int> >cost;
    std::vector<int> money(p);
    std::vector<int> coach(s);

    for (auto i = 0; i < p; i++) {
      auto k = -1;
      std::cin >> k;
      std::vector<int> prize(k);

      for (auto j = 0; j < k; j++) {
        std::cin >> prize[j];
      }
      cost.push_back(prize);
      std::cin >> money[i];

    }
    for (auto i = 0; i < s; i++) std::cin >> coach[i];

    auto result = 0;
    for (auto i = 0; i < p; i++) {
      while (can_claim_prize(cost[i], coach)) {
        result += money[i];
      }
    }
    std::cout << result << std::endl;
  }
  return 0;
}
