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

int and_operation(int a, int b) {
    if (a == 0 or b == 0) {
        return 0;
    }
    if (a == 1 and b == 1) {
        return 1;
    }
    return -1;
}

int or_operation(int a, int b) {
    if (a == 1 or b == 1) {
        return 1;
    }
    if (a == 0 and b == 0) {
        return 0;
    }
    return -1;
}


void perform_instruction(std::vector<int> &reg, std::string ins, int a, int b) {
    if(ins == "SET") {
        reg[a] = 1;
    } else if (ins == "CLEAR") {
        reg[a] = 0;
    } else if (ins == "OR") {
        reg[a] = or_operation(reg[a], reg[b]);
    } else if (ins == "AND") {
        reg[a] = and_operation(reg[a], reg[b]);
    }
}


int main(void) {
    int n = 0;
    while (std::cin >> n) {
        if (n == 0) break;
        std::string ins;
        int a = -1, b = -1;
        std::vector<int>reg(32, -1);
        for (int i = 0; i < n; i++) {
            std::cin >> ins;

            if(ins == "SET") {
                std::cin >> a;
                perform_instruction(reg, ins, a, -1);
            } else if (ins == "CLEAR") {
                std::cin >> a;
                perform_instruction(reg, ins, a, -1);
            } else if (ins == "OR") {
                std::cin >> a >> b;
                perform_instruction(reg, ins, a, b);
            } else if (ins == "AND") {
                std::cin >> a >> b;
                perform_instruction(reg, ins, a, b);
            }
        }
        for (int i = 31; i >= 0; i--) {
            if (reg[i] == -1) {
                std::cout << "?";
            } else {
                std::cout << reg[i];
            }
        }
        std::cout << std::endl;
    }

  return 0;
}
