// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// DEBUG STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<typename ttype> void debug(std::vector<ttype> &vec) {
  std::cerr << "DEBUG LOG :: vector [";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cerr << *it << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void debug(std::map<ttype, ttype> &m) {
  std::cerr << "DEBUG LOG :: map [";
 for (auto it = m.begin(); it != m.end(); it++) {
    std::cerr << it->first << "=" << it->second << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void debug(ttype val) {
  std::cerr << "DEBUG LOG :: object [" << val << "]" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// GRAPH STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
enum {
      VISITED = 1,
      UNVISITED  =-1
};

int R = -1, C = -1;

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

bool trick(std::vector<int>& cards) {
  std::queue<int> q;
  for (int i = 0; i < cards.size(); i++) {
    q.push(cards[i]);
  }

  auto k = 1;
  while (!q.empty()) {
    for (auto i = 0; i < k; i++) {
      auto num = q.front();
      q.pop();
      q.push(num);
    }
    auto num = q.front();
    q.pop();
    std::cout << "num = " << num << "" << std::endl;
    if (num != k) {
      return false;
    }
    k += 1;
  }
  return true;
}


int main(void) {
  auto testcases = -1;
  std::cin >> testcases;


  for (auto testcase = 0; testcase < testcases; testcase++) {
    std::vector<int> cards;
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
      cards.push_back(n);
    }

    while (next_permutation(cards.begin(), cards.end());
  }

  std::vector<int> cards{3, 1, 4, 5, 2};
  auto result = trick(cards);
  std::cout << result << std::endl;

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
