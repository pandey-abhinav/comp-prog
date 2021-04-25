// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// MACROS
#define INF std::numeric_limits<int>::max()
#define EPS 1e-9

#define MAX_N 1000005

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// DEBUG STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<typename ttype> void debug(std::vector<ttype> &vec) {
  std::cerr << "DEBUG LOG :: vector [";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cerr << *it << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void debug(std::map<ttype, ttype> &m) {
  std::cerr << "DEBUG LOG :: map [";
 for (auto it = m.begin(); it != m.end(); it++) {
    std::cerr << it->first << "=" << it->second << " ";
  }
  std::cerr << "]" << std::endl;
}

template<typename ttype> void debug(ttype val) {
  std::cerr << "DEBUG LOG :: object [" << val << "]" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// GRAPH STUFF /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
enum {
      VISITED = 1,
      UNVISITED  =-1
};

int R = -1, C = -1;

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printArray(std::vector<int> &arr) {
    for (auto i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void inversions(std::vector<int> &arr, int &inv, int left, int right) {
    // std::cout << "left = " << left << ", right = " << right << std::endl;

    if (left == right) {
        return;
    }
    auto mid = (left + right) / 2;
    inversions(arr, inv, left, mid);
    inversions(arr, inv, mid + 1, right);

    std::vector<int> temp;

    auto i = left, j = mid + 1;

    while (i <= mid and j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            inv = inv + mid - i + 1;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (auto k = 0; k <= right - left; k++) {
        arr[k + left] = temp[k];
    }

    // std::cout << "merge :: left = " << left << ", right = " << right << std::endl;
    // printArray(arr);

}

int main(void) {

    int n;
    std::cin >> n;

    std::vector<int>startArr(n), endArr(n);
    for (auto i = 0; i < n; i++) {
        std::cin >> startArr[i];
    }
    for (auto i = 0; i < n; i++) {
        std::cin >> endArr[i];
    }

    auto a = 0, b = 0;

    inversions(startArr, a, 0, n - 1);
    inversions(endArr, b, 0, n - 1);

    // std::cout << "a = " << a << ", b = " << b << std::endl;

    if (abs(a - b) % 2 == 0) {
        std::cout << "Possible" << std::endl;
    } else {
        std::cout << "Impossible" << std::endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// GEOMETRY STUFF //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
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
