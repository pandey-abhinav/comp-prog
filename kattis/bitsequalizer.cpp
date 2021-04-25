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

  for (auto testcase = 1; testcase <= testcases; testcase++) {
    std::string S, T;
    std::cin >> S >> T;
    auto num_S1_T0 = 0, num_S0_T1 = 0, num_SQ_T1 = 0, num_SQ_T0 = 0;
    for (auto i = 0; i < S.length(); i++) {
      if (S[i] == '1' and T[i] == '0') num_S1_T0 += 1;
      if (S[i] == '0' and T[i] == '1') num_S0_T1 += 1;
      if (S[i] == '?' and T[i] == '1') num_SQ_T1 += 1;
      if (S[i] == '?' and T[i] == '0') num_SQ_T0 += 1;
    }
    if (num_S1_T0 > num_S0_T1 + num_SQ_T1) {
      std::cout << "Case " << testcase << ": -1" << std::endl;
    } else {
      auto result = -1;
      if (num_S1_T0 >= num_S0_T1) {
        result = num_SQ_T0 + num_S0_T1 + (num_S1_T0 - num_S0_T1) * 2 + (num_S0_T1 + num_SQ_T1 +  - num_S1_T0);
      } else {
        result = num_SQ_T0 + num_S0_T1 + num_SQ_T1;
      }
      std::cout << "Case " << testcase << ": " << result << std::endl;
    }
  }
  return 0;
}
