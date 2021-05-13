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

using namespace std;

bool anagram(string a, string b, int n) {
    // cout << a << " " << b << endl;
    int fa[30], fb[30];
    for (int i = 0; i < 30; i++) {
        fa[i] = 0;
        fb[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        fa[a[i] - 'a'] += 1;
        fb[b[i] - 'a'] += 1;
    }
    for (int i = 0; i < 30; i++) {
        if (fa[i] != fb[i]) {
            // cout << "false at " << i << endl;
            return false;
        }
    }
    return true;
}
    
int main(void) {
    string s;
    cin >> s;
    bool found = false;
    for (int l = 1; l <= s.size() / 2; l++) {
        bool check = true;
        for (int i = l; i < s.size(); i = i + l) {
            if (!anagram(s.substr(0, l), s.substr(i, l), l)) {
                check = false;
                break;
            }
        }
        if (check == true) {
            cout << s.substr(0, l) << endl;
            found = true;
            break;
        }
    }
    if (found  == false) {
        cout << -1 << endl;
    }
    return 0;
}
