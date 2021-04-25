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
  int n, k;
  std::cin >> n;
  std::cin.ignore();

  bool r_found = false;
  std::string r_found_name = "";

  for (int i = 0; i < n; i++) {
    bool pea_check = false, pan_check =false;
    std::string r_name, item_name;

    std::cin >> k;
    std::cin.ignore();

    std::getline(std::cin, r_name);

    for (int j = 0; j < k; j++) {
      std::getline(std::cin, item_name);
      if (item_name == "pea soup") pea_check = true;
      if (item_name == "pancakes") pan_check = true;
   }
    if (not r_found and pea_check and pan_check) {
      r_found = true;
      r_found_name = r_name;
    }
  }

  if (r_found) {
    std::cout << r_found_name << std::endl;
  } else {
    std::cout << "Anywhere is fine I guess" << std::endl;
  }
  return 0;
}
