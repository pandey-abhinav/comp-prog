#include <iostream>
#include <vector>
#include <string>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<std::string> names;
  std::string name;

  for (int i = 0; i < n; i++) {
    std::cin >> name;
    names.push_back(name);
  }
  int result = -1;
  int initial_order = names[1] > names[0] ? 1 : -1;

  for (int i = 2; i < n; i++) {
    int order = names[i] > names[i - 1] ? 1 : -1;
    if (order != initial_order) {
      result = 0;
      break;
    }
  }
  if (result == 0) {
    std::cout << "NEITHER" << std::endl;
  } else if (initial_order == 1) {
    std::cout << "INCREASING" << std::endl;
  } else {
    std::cout << "DECREASING" << std::endl;
  }
  return 0;
}
