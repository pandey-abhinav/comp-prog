#include <cstdio>
#include <cmath>

int main(void) {
  long long int x, n, p, sum = 0;

  std::scanf("%lld", &x);
  std::scanf("%lld", &n);

  for (int i = 0; i < n; i++) {
    std::scanf("%lld", &p);
    sum = sum + (x - p);
  }

  sum = sum + x;
  std::printf("%lld\n", sum);
}
