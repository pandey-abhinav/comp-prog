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


class teque {

    void push_front(int n) {

    }
}

int main(void) {
    int n;
    std::cin >> n;

    std::list<int>l;
    std::string cmd;
    int idx;
    for (int i = 0; i < n; i++) {
        std::cin  >> cmd >> idx;
        vector<int>front, back;
        std::cin.ignore();
        if (cmd == "push_front") {
            if (l.size() % 2 == 0) {
                front.push_back(it);
            }
            l.push_front(idx);
        } else if (cmd == "push_back") {
            back.push_back(
        } else if (cmd == "push_middle") {
            l.insert(it);
        } else {

        }
    }
    return 0;
}
