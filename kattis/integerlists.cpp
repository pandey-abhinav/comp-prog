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


void print_list(std::list<int> l) {
    auto it = l.begin();
    for (auto i = 0; i < l.size(); i++) {
        printf("%d", *it);
        if (i != l.size() - 1) {
            printf(",");
        }
        it++;
    }
}

void print_list_reverse(std::list<int> l) {
    auto it = l.rbegin();
    for (auto i = 0; i < l.size(); i++) {
        printf("%d", *it);
        if (i != l.size() - 1) {
            printf(",");
        }
        it++;
    }
}


int main(void) {

    auto testcases = -1;
    scanf("%d\n", &testcases);
    for (auto testcase = 0; testcase < testcases; testcase++) {

        char commands[100010];
        std::list<int>l;
        int n;

        scanf("%s\n", commands);
        scanf("%d\n", &n);

        scanf("[");
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            if (i != n - 1) {
                scanf(",");
            }
            l.push_back(temp);
        }
        scanf("]");

        // printf("commands = [%s]\n", commands);
        // printf("list = [");
        // for (auto it = l.begin(); it != l.end(); it++) {
        //     printf("%d,", *it);
        // }
        // printf("]\n");

        int dir = 1, err = 0, m = strlen(commands);

        for (int i = 0; i < m; i++) {
            int f = l.front();
            // printf("%d\n", f);
            if (commands[i] == 'R') {
                dir = 1 - dir;
            } else {
                if (l.empty()) {
                    err = 1;
                    break;
                }
                if (dir == 1) {
                    l.pop_front();
                } else {
                    l.pop_back();
                }
            }
        }
        if (err == 1) {
            printf("error\n");
        } else  {
            // printf("dir = %d\n", dir);
            printf("[");
            if (dir == 1) {
                print_list(l);
            } else {
                print_list_reverse(l);
            }
            printf("]\n");
        }
    }
    return 0;
}
