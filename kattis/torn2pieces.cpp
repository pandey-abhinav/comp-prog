// C LIBRARIES
#include <cstring>
#include <cmath>

// C++ LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
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

using namespace std;

int adj[1005][1005];
int parent[1005];
int state[1005];
map<string,int> idx;
map<int,string> name;
int k = 0;




int find_index(string s) {
    if (idx.find(s) == idx.end()) {
        idx[s] = k;
        name[k] = s;
        k += 1;
    }
    return idx[s];
}

void insert_node(int u, int v) {
    // cout << "insert = " << u << ", " << v << ", k = " << k << endl;
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void dfs(int u) {
    // cout << "dfs : " << u << endl;
    state[u] = VISITED;
    for (int v = 0; v < k; v++) {
        if (adj[u][v] == 1 and state[v] == UNVISITED) {
            parent[v] = u;
            dfs(v);
        }
    }
}

int main(void) {
    memset(adj, 0, sizeof(adj[0][0]) * 1005 * 1005);
    memset(parent, -1, sizeof(parent[0]) * 1005);
    memset(state, UNVISITED, sizeof(state[0]) * 1005);


    int n;
    cin >> n;

    cin.ignore();
    for (int i = 0; i < n; i++) {
        string l;
        getline(cin, l);
        // // cout << "l = [" << l << "]" << endl;

        istringstream iss(l);

        string s;
        iss >> s;
        int u = find_index(s);
        
        for (;iss >> s;) {
            int v = find_index(s);
            insert_node(u, v);

        }
    }

    string u, v;
    cin >> u >> v;
    int ui = find_index(u), vi = find_index(v);

    // cout << ui << " " << vi << endl;

    // cout << "k = " << k << endl;

    dfs(ui);

    // for (int i = 0; i < k; i++) {
    //     for (int j = 0; j < k; j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
                                 
    // for (int i = 0; i < k; i++) {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;

    if (state[vi] == VISITED) {
        vector<int>result;
        int p = parent[vi];
        result.push_back(vi);
        while (p != -1) {
            result.push_back(p);
            p = parent[p];
        }
        for (int i = result.size() - 1; i > 0; i--) {
            cout << name[result[i]] << " ";
        }
        cout << name[result[0]] << endl;
    } else {
        cout << "no route found" << endl;
    }
    
    return 0;
}
