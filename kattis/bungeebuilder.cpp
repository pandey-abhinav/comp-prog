// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
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

int main(void) {
    int n;
    std::cin >> n;

    std::stack<int>s;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        s.push(temp);
    }

    if (s.size() < 3) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int ans = 0;
    int cur_min = std::numeric_limits<int>::max();
    s.pop();
    std::cout << "cur_min = " << cur_min << ", end = " << end << std::endl;
    while (!s.empty()) {
        int cur = s.top();
f        s.pop();

        if (cur > prev) {

        }

        low = std::min(low, cur);
        std::cout << "cur = " << cur << ", end = " << end << ", ans = " << ans << std::endl;
        if (cur > end) {
            ans = std::max(ans, std::min(cur, end) - low);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
