// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <vector>
#include <string>

#define EPS 1e-9

// GEOMETRY CLASSES
class point {

public:
  double x, y;

  point() {
    this->x = 0;
    this->y = 0;
  }

  point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  point operator +(const point other) {
    point result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
  }

  point operator -(const point other) {
    point result;
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
  }

  bool operator <(point other) {
    if (std::fabs(this->x - other.x) > EPS) {
      return this->x < other.x;
    }
    return this->y < other.y;
  }

  bool operator ==(const point other) {
    return std::fabs(this->x - other.x) < EPS and std::fabs(this->y - other.y) < EPS;
  }
};

double Euclidean(point a, point b) {
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int main(void) {
  auto m = -1;

  std::cin >> m;
  for (int t = 0; t < m; t++) {

    point book;
    std::cin >> book.x >> book.y;

    auto n = -1;
    std::cin >> n;
    point candle;

    bool light = false;
    for (int i = 0; i < n; i++) {
      std::cin >> candle.x >> candle.y;
      if (Euclidean(book, candle) - 8.0 < EPS) {
        light = true;
      }
    }
    if (light == true) {
      std::cout << "light a candle" << std::endl;
    } else {
      std::cout << "curse the darkness" << std::endl;
    }
  }
  return 0;
}
