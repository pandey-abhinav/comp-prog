// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005

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
////////////////////////////// DEBUG STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template<typename ttype> void DEBUG(std::vector<ttype> &vec) {
  std::cerr << "DEBUG LOG :: vector [";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cerr << *it << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void DEBUG(std::map<ttype, ttype> &m) {
  std::cerr << "DEBUG LOG :: map [";
 for (auto it = m.begin(); it != m.end(); it++) {
    std::cerr << it->first << "=" << it->second << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void DEBUG(ttype val) {
  std::cerr << "DEBUG LOG :: object [" << val << "]" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(void) {
  int n;
  while (std::cin >> n) {
    DEBUG(n);
    std::vector<int>die_roll(n);
    std::vector<int>freq_die_roll(10);
    std::map<int,int> player;

    for (auto i = 0; i < n;i ++) {
      std::cin >> die_roll[i];
      freq_die_roll[die_roll[i]] += 1;
      player[die_roll[i]] = i + 1;
    }

    DEBUG(die_roll);
    DEBUG(freq_die_roll);
    DEBUG(player);

    auto result = -1;
    for (auto d = 6; d > 0; d--) {
      if (freq_die_roll[d] == 1) {
        result = d;
        break;
      }
    }

    if (result != -1) {
      std::cout << player[result] << std::endl;
    } else {
      std::cout << "none" << std::endl;
    }

  }
  return 0;
}
