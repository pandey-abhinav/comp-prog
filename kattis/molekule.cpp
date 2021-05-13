// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
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

    std::vector<std::vector<int> >adj(n + 1, std::vector<int>());
    std::vector<std::pair<int, int> >edge_list;

    // std::cout << n << std::endl;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        // std::cout << "(" << u << ", " << v << ")" << std::endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_list.push_back(std::make_pair(u, v));
    }
    std::queue<int>q;
    std::vector<int> color(n + 1, -1);
    
    int s = 1;
    q.push(s);
    color[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     std::cout << color[i] << " ";
    // }
    // std::cout << std::endl;

    for (int i = 0; i < n - 1; i++) {
        if (color[edge_list[i].first] == 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
