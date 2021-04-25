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
      UNVISITED  = 0
};

int status[1100][1100];
char arr[1100][1100];

int R = -1, C = -1;

int dr[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void floodfill(int r, int c, int cluster) {
  status[r][c] = cluster;

  for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr >= 0 and nc >= 0 and nr < R and nc < C
        and status[nr][nc] == UNVISITED
        and arr[nr][nc] == arr[r][c]) {
      floodfill(nr, nc, cluster);

    }
  }
}

int main(void) {
  std::cin >> R >> C;
  for (int i = 0; i < R; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i< R; i++) {
    for (int j = 0; j < C; j++) {
      status[i][j] = UNVISITED;
    }
  }

  int cluster = 1;

  for (int i = 0; i< R; i++) {
    for (int j = 0; j < C; j++) {
      if (status[i][j] == UNVISITED) {
        floodfill(i, j , cluster);
        cluster++;
      }
    }
  }


  // for (int i = 0; i< R; i++) {
  //   for (int j = 0; j < C; j++) {
  //     std::cout << status[i][j];
  //   }
  //   std::cout << std::endl;
  // }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int sr, sc, fr, fc;
    std::cin >> sr >> sc >> fr >> fc;


    if (status[sr - 1][sc - 1] == status[fr - 1][fc - 1]) {
      if (arr[sr - 1][sc - 1] == '1') {
        std::cout << "decimal" << std::endl;
      } else {
        std::cout << "binary" << std::endl;
      }
    } else {
      std::cout << "neither" << std::endl;
    }
  }
  return 0;
}
