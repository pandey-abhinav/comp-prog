#include <cstdio>
#include <cmath>

int main(void) {
  int x, y;

  while (std::scanf("%d %d", &x, &y) != EOF) {
    int quad = -1;
    if (x > 0) {
      if (y > 0) quad = 1; else quad = 4;
    } else {
      if (y > 0) quad = 2; else quad = 3;
    }
    std::printf("%d\n", quad);
  }
  return 0;
}
