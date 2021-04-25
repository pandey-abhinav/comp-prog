#include <iostream>
#include <string>
#include <cstring>

int main(void) {
  int t;
  char p;
  std::string v;

  int primary_score = 0, secondary_score = 0;
  int problem_status[30], problem_time[30];
  std::memset(problem_status, 0, 30 * sizeof(int));
  std::memset(problem_time, 0, 30 * sizeof(int));

  while(std::cin >> t) {
    if (t == -1) {
      break;
    }
    std::cin >> p >> v;

    if (problem_status[p - 65] == 1) continue;

    // std::cout << t << " " << p << " " << v << " " << std::endl;
    if (v.compare("right") == 0) {
      problem_status[p - 65] = 1;
      primary_score += 1;
      secondary_score += t + problem_time[p - 65];
    } else {
       problem_time[p - 65] += 20;
    }
  }
  std::cout << primary_score << " " << secondary_score << std::endl;
  return 0;
}
