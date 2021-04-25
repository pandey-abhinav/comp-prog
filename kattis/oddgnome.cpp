#include <cstdio>
#include <cmath>
#include <limits>
#include <algorithm>

int main(void) {
  int n = -1;
  std::scanf("%d", &n);

  for (int t = 0; t < n; t++) {
    int gnome[1005], g = -1, king = -1;
    std::scanf("%d", &g);

    for (int i = 0; i < g; i++) {
      std::scanf("%d", &gnome[i]);
      if (i == 0) {
        continue;
      }
      // printf("gnome[i] = %d, gnome[i - 1] = %d\n", gnome[i], gnome[i - 1]);
      if (king == -1 and gnome[i] != gnome[i - 1] + 1) {
        king = i + 1;
      }
    }
    std::printf("%d\n", king);
  }
  return 0;
}
