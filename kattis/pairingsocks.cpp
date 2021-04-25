// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
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

int main(void) {

  long long int n;
  std::cin >> n;

  std::vector<int> socks;
  std::stack<int>pile, aux_pile;
  int s;

  for (int i = 0; i < 2 * n; i++) {
    std::cin >> s;
    socks.push_back(s);
  }

  for (int i = 2 * n - 1; i >= 0 ; i--) {
    pile.push(socks[i]);
  }

  int moves = 0;
  while (!pile.empty()) {
    // std::cout << "pile size = " << pile.size() << std::endl;
    // std::cout << "aux pile size = " << aux_pile.size() << std::endl;

    // std::cout << "pile top = " << pile.top() << std::endl;
    // if (!aux_pile.empty()) {
    //   std::cout << "aux pile top = " << aux_pile.top() << std::endl;
    // }

    // std::cout << std::endl;

    if (!aux_pile.empty() and pile.top() == aux_pile.top()) {
      // std::cout << "value same with v = " << pile.top() << std::endl;
      moves += 1;
      pile.pop();
      aux_pile.pop();
    } else {
      aux_pile.push(pile.top());
      pile.pop();
      moves += 1;
    }
  }
  if (!aux_pile.empty()) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << moves << std::endl;
  }

  return 0;
}
