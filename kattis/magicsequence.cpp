// C LIBRARIES
#include <cstring>
#include <cmath>
#include <climits>

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

void counting_sort(std::vector<long long int>&arr, int d) {
    auto m = 1;
    for (auto i = 0; i < d; i++) {
        m = m * 10;
    }
    long long int l = LLONG_MAX, r = LLONG_MIN;
    for (auto i = 0; i < arr.size(); i++) {
        l = std::min(l, arr[i] % m);
        r = std::max(r, arr[i] % m);
    }

    std::vector<int> freq(r - l + 1, 0);
    for (auto i = 0; i < arr.size(); i++) {
        freq[arr[i] % m - l]++;
    }
    for(auto i = 1; i < freq.size(); i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    std::vector<int>temp(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        temp[freq[arr[i] % m - l] - 1] = arr[i];
        freq[arr[i] % m - l] -= 1;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = temp[i];
    }
}

void radix_sort(std::vector<long long int>&arr) {
    for (int i = 1; i < 10; i++) {
        counting_sort(arr, i);
    }
}



int main(void) {
    auto testcases = -1;
    std::cin >> testcases;

    for (auto testcase = 0; testcase < testcases; testcase++) {
        long long int n, a, b, c, x, y;
        std::cin >> n;
        std::cin >> a >> b >> c;
        std::cin >> x >> y;

        std::vector<long long int>s;
        s.push_back(a);

        for (auto i = 1; i < n; i++) {
            s.push_back((s[i - 1] * b + s[0]) % c);
        }

        radix_sort(s);

        long long int v = 0;
        for (auto i = 0; i < n; i++) {
            v = (v * x + s[i]) % y;
        }
        std::cout << v << std::endl;
    }
    return 0;
}
