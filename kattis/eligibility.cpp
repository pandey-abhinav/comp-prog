#include <cstdio>
#include <cmath>

int main(void) {

  int testcases;
  std::scanf("%d", &testcases);
  for (int t = 0; t < testcases; t++) {

    // input
    int sy, sm, sd, by, bm, bd, c;
    char name[35];
    std::scanf("%30s %d/%d/%d %d/%d/%d %d", name, &sy, &sm, &sd, &by, &bm, &bd, &c);

    if (sy >= 2010 or by >= 1991) {
      std::printf("%s eligible\n", name);
    } else if (c >= 41) {
      std::printf("%s ineligible\n", name);
    } else {
      std::printf("%s coach petitions\n", name);
    }
  }
  return 0;
}
