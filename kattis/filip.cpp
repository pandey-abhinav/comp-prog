#include <cstdio>
#include <cmath>
#include <limits>
#include <algorithm>

int reverse(int num) {
  int result = 0;
  while (num > 0) {
    result = result * 10 + (num  % 10);
    num /= 10;
  }
  return result;

}

int main(void) {
  int a = -1, b = -1;
  while(std::scanf("%d %d", &a, &b) != EOF) {
    std::printf("%d\n", std::max(reverse(a), reverse(b)));
  }
  return 0;
}
