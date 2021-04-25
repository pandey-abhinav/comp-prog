// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
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
  auto testcases = -1;
  std::cin >> testcases;

  for (auto testcase = 0; testcase < testcases; testcase++) {
    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string> > input;
    std::string name, clas, cl;

    for (auto i = 0; i < n; i++) {
      std::cin >> name >> clas >> cl;
      input.push_back(make_pair(name.substr(0, name.length - 2),
    }
  }

  return 0;
}
