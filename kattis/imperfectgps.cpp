// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

#define EPS 1e-5

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

double Walk(std::vector<std::pair<int, point> > points) {
  auto walk = 0.0;
  for (int i = 1; i < points.size(); i++) {
    walk += Euclidean(points[i].second, points[i - 1].second);
  }
  return walk;
}

int main(void) {
  int n = -1;
  double t = 0.0;

  std::cin >> n >> t;
  std::vector<std::pair<int, point> > path(n), gps;

  for (int i = 0; i < n; i++) {
    std::cin >> path[i].second.x >> path[i].second.y >> path[i].first;
  }

  int current_time = path[0].first;
  gps.push_back(path[0]);

  while (true) {
    current_time += t;

    if (current_time > path[n-1].first) {
      gps.push_back(path[n-1]);
      break;
    }

    auto start_point = std::lower_bound(path.begin(), path.end(), current_time,
                                        [](const std::pair<int, point>path_point, int value){
                                          return path_point.first < value;
                                        });
    auto index = std::distance(path.begin(), start_point);

    double speed_x = (path[index].second.x - path[index-1].second.x) / (path[index].first - path[index - 1].first);
    double speed_y = (path[index].second.y - path[index-1].second.y) / (path[index].first - path[index - 1].first);

    double nx = path[index - 1].second.x + speed_x * (current_time - path[index - 1].first);
    double ny = path[index - 1].second.y + speed_y * (current_time - path[index - 1].first);

    gps.push_back(std::make_pair(current_time, point(nx,ny)));

  }
  auto total_run = Walk(path), total_gps = Walk(gps);
  std::cout << std::setprecision(20) << std::abs(total_run - total_gps) / total_run * 100 << std::endl;
}
