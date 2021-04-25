#include <cstdio>
#include <cmath>

int main(void) {
  int n, x;
  std::scanf("%d", &n);
  for (int t = 0; t < n; t++) {
    std::scanf("%d", &x);
    if (x % 2 == 0) std::printf("%d is even\n", x);
    else std::printf("%d is odd\n", x);
  }
}
