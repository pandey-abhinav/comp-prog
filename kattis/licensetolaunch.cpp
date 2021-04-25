#include <cstdio>
#include <cmath>
#include <limits>
#include <algorithm>

int main(void) {
  int n;

  while(std::scanf("%d", &n) != EOF) {
    int arr[1000005], min_arr = std::numeric_limits<int>::max(), min_arr_idx = -1;

    for (int i = 0; i < n; i++) {
      std::scanf("%d", &arr[i]);
      if (arr[i] < min_arr) {
        min_arr = arr[i];
        min_arr_idx = i;
      }
    }
    std::printf("%d\n", min_arr_idx);
  }
  return 0;
}
