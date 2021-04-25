#include <cstdio>
#include <cmath>
#include <algorithm>

int main(void) {
  int n, t = 1;

  while(std::scanf("%d", &n) != EOF) {
    int arr[50];

    for (int i = 0; i < n; i++) {
      std::scanf("%d", &arr[i]);
    }

    int min_arr = *std::min_element(arr, arr + n);
    int max_arr = *std::max_element(arr, arr + n);

    std::printf("Case %d: %d %d %d\n", t, min_arr, max_arr, max_arr - min_arr);

    t += 1;
  }
  return 0;
}
