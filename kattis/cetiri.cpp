#include <iostream>
#include <algorithm>

int main(void) {
  int arr[5];
  for (int i = 0; i < 3; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + 3);
  int result = -1;

  if (arr[2] - arr[1] > arr[1] - arr[0]) {
    result = arr[1] + (arr[1] - arr[0]);
  } else if (arr[2] - arr[1] < arr[1] - arr[0]) {
    result = arr[0] + (arr[2] - arr[1]);
  } else if (arr[2] - arr[1] == arr[1] - arr[0]) {
    result = arr[2] + (arr[1] - arr[0]);
  }

  std::cout << result << std::endl;
  return 0;
}
