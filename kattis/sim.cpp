// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
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

void print_list(std::list<char> l) {
    std::cout << "[";
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
}

int main(void) {
  auto testcases = -1;
  std::cin >> testcases;
  std::cin.ignore();

  for (auto testcase = 0; testcase < testcases; testcase++) {
      std::string input;
      std::getline(std::cin, input);
      std::list<char>l;
      auto it = l.end();

      // std::cout << "testcase = " << testcase << std::endl;


      for (int i = 0; i < input.size(); i++) {
          // std::cout << "command = [" << input[i] << "]" << std::endl;
          // print_list(l);

          if (input[i] == '[') {
              it = l.begin();
          } else if (input[i] == ']') {
              it = l.end();
          } else if (input[i] == '<') {
              if (it != l.begin()) {
                  it--;
                  it = l.erase(it);
              }
          } else {
              l.insert(it, input[i]);
          }

          // print_list(l);
          // std::cout << std::endl;
      }
      for (it = l.begin(); it != l.end(); it++) {
          std::cout << *it;
      }
      std::cout << std::endl;
  }

  return 0;
}
