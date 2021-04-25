#include <cstdio>
#include <cmath>

int main(void) {
  long long int a, b;
  while(std::scanf("%lld %lld", &a, &b) != EOF) {
    std::printf("%lld\n", std::abs(a - b));
  }
  return 0;
}
