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
  int testcase = 1;
  while (std::cin >> n) {
    DEBUG(n);

    std::vector<int>arr(n);
    for (auto i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
    DEBUG(arr);

    sort(arr.begin(), arr.end());



  //   std::vector<int>sums;
  //   for (int i = 0; i < n; i++) {
  //     for (int j = i + 1; j < n; j++) {
  //       if (arr[i] != arr[j]) sums.push_back(arr[i] + arr[j]);
  //     }
  //   }
  //   sort(sums.begin(), sums.end());
  //   DEBUG(sums);

  //   std::cout << "Case " << testcase << ":" << std::endl;
  //   testcase += 1;

  //   int m;
  //   std::cin >> m;
  //   for (auto i = 0; i < m; i++) {
  //     int q;
  //     std::cin >> q;
  //     auto r = lower_bound(sums.begin(), sums.end(), q) - sums.begin();
  //     if (r == 0) {
  //       std::cout << "Closest sum to  " << q << " is " << sums[r] << "." <<  std::endl;
  //     } else if (r == sums.size()) {
  //       std::cout << "Closest sum to  " << q << " is " << sums[r - 1] << "." <<  std::endl;
  //     } else {
  //       if (std::abs(q - sums[r]) < std::abs(q - sums[r-1])) {
  //         std::cout << "Closest sum to  " << q << " is " << sums[r]  << "." <<  std::endl;
  //       } else {
  //         std::cout << "Closest sum to  " << q << " is " << sums[r - 1]  << "." <<  std::endl;
  //       }
  //     }

  //   }

  // }

  return 0;
}
