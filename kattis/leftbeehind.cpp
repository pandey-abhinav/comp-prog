#include <cstdio>
#include <cmath>

int main(void) {

  int x, y;
  while(std::scanf("%d %d", &x, &y), (x or y)) {
    if (x + y == 13) {
      std::printf("Never speak again.\n");
    } else if (x > y) {
      std::printf("To the convention.\n");
    } else if (x < y) {
      std::printf("Left beehind.\n");
    } else if (x == y) {
      std::printf("Undecided.\n");
    }
  }
  return 0;
}
