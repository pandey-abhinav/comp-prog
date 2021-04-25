#include <string>
#include <iostream>

int main(void) {
  std::string x;

  while (std::cin >> x, x.compare("END")) {
    int i = 1;
    while (true) {
      int y = x.length();
      if (x.compare(std::to_string(y)) == 0) {
        std::cout << i << std::endl;
        break;
      }
      x = std::to_string(y);
      i += 1;
    }

  }
  return 0;
}
