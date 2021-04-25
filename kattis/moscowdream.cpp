#include <cstdio>
#include <cmath>

int main(void) {
  int a, b, c, n;

  while (std::scanf("%d %d %d %d", &a, &b, &c, &n) != EOF) {
    if (a + b + c < n or n < 3 or a == 0 or b == 0 or c == 0) {
      std::printf("NO\n");
    } else {
      std::printf("YES\n");
    }
  }
  return 0;
}
