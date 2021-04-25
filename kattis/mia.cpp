#include <cstdio>
#include <cmath>
#include <limits>
#include <algorithm>

void check_bigger(int s, int r) {
  if (s > r) {
    std::printf("Player 1 wins.\n");
  } else if (r > s) {
    std::printf("Player 2 wins.\n");
  } else {
    std::printf("Tie.\n");
  }
}

int main(void) {
  int s0, s1, r0, r1;

  while (std::scanf("%d %d %d %d", &s0, &s1, &r0, &r1), (s0 or s1 or r0 or r1)) {
    int s = std::max(s0, s1) * 10 + std::min(s0, s1);
    int r = std::max(r0, r1) * 10 + std::min(r0, r1);

    if (s == 21 or r == 21) {
      // 12/21 case

      if (s == 21 and r == 21) {
        std::printf("Tie.\n");
      } else if (s == 21) {
        std::printf("Player 1 wins.\n");
      } else if (r == 21) {
        std::printf("Player 2 wins.\n");
      }

    } else if (s0 == s1 or r0 == r1) {
      // doubles case

      if (s0 == s1 and r0 == r1) {
        check_bigger(s, r);
      } else if (s0 == s1) {
        std::printf("Player 1 wins.\n");
      } else if (r0 == r1) {
        std::printf("Player 2 wins.\n");
      }
    } else {
      // normal case

      check_bigger(s, r);
    }
  }
  return 0;
}
