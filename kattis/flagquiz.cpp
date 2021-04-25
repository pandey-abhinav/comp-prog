// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005


////////////////////////////////////////////////////////////////////////////////

int main(void) {
  std::string line;
  int n;
  std::getline(std::cin, line);
  std::cin >> n;
  std::cin.ignore();

  std::vector<std::string>input;
  std::vector<std::vector<std::string> >options(n);
  int idx = 0;

  for (auto i = 0; i < n; i++) {
    std::getline(std::cin, line);
    input.push_back(line);
    size_t ppos = 0, cpos = line.find(", ", ppos);
    std::string option;

    while(cpos != std::string::npos) {
      option = line.substr(ppos, cpos - ppos);
      options[idx].push_back(option);

      ppos = cpos + 2;
      cpos = line.find(", ", ppos);
    }
    option = line.substr(ppos, cpos - ppos);
    options[idx].push_back(option);
    idx += 1;

  }
  std::vector<int>cost(n, 0);
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < n; j++) {
      int c =  0;
      for (auto k = 0; k < options[i].size(); k++) {
        if (options[i][k] != options[j][k]) {
          c += 1;
        }
      }
      cost[i] = std::max(cost[i], c);
    }
  }
  int min_cost = std::numeric_limits<int>::max();
  for (auto i = 0; i < n; i++) {
    min_cost = std::min(cost[i], min_cost);
  }

  for (auto i = 0; i < n; i++) {
    if (cost[i] == min_cost) {
      std::cout << input[i] << std::endl;
    }
  }
  return 0;
}
