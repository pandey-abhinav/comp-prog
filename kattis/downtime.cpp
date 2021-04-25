// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <utility>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005


////////////////////////////////////////////////////////////////////////////////

int main(void) {
  auto n = -1, k = -1;
  std::cin >> n >> k;

  std::multiset<std::pair<int, int> >ts;
  for (auto i = 0; i < n; i++) {
    auto t = -1;
    std::cin >> t;
    ts.insert(std::make_pair(t, 1));
    ts.insert(std::make_pair(t + 1000, -1));
  }

  auto cur_req  = 0, max_req = -1;
  for (auto it = ts.begin(); it != ts.end(); it++) {
    cur_req += it->second;
    max_req = std::max(max_req, cur_req);
  }

  auto res = -1;
  if (max_req % k == 0) {
    res = max_req / k;
  } else {
    res = max_req / k + 1;
  }

  std::cout << res << std::endl;

  return 0;
}
