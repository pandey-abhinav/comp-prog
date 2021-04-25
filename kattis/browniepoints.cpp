#include <iostream>
#include <vector>
#include <string>
#include <cstring>


class point {

public:
  int x, y;

  point() {
    this->x = 0;
    this->y = 0;
  }

  point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  point operator +(point other) {
    point result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
  }

  point operator -(point other) {
    point result;
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
  }

  int quadrant() {
    if (this->x > 0) {
      if (this->y > 0) {
        return 1;
      } else if (this->y < 0) {
        return 4;
      }
    } else if (this->x < 0) {
      if (this->y > 0) {
        return 2;
      } else if (this->y < 0) {
        return 3;
      }
    }
    return -1;
  }
};

/*
 Geometry classes required for the problem are defined above.
 */

std::vector<point> points;

int main(void) {
  auto n = -1;

  while(std::cin >> n, n != 0) {

    points.clear();
    points.resize(n);
     for (int i = 0; i < n; i++) {
      std::cin >> points[i].x >> points[i].y;
    }

    auto origin = points[n/2];
    auto stan = 0, ollie = 0;

    for (int i = 0; i < n; i++) {
      auto quad = (points[i] - origin).quadrant();
      if (quad == 1 or quad == 3) stan += 1;
      if (quad == 2 or quad == 4) ollie += 1;
    }
    std::cout << stan << " " << ollie << std::endl;
  }
  return 0;
}
