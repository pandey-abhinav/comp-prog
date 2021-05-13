#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int test;
    cin >> test;

    while (test > 0) {
        test -= 1;
        
        long long int A, B, n, a[100005], b[100005];
        bool check = false;

        cin >> A >> B >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long int total_damage = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] % A == 0) {
                total_damage += (b[i] / A) * a[i];
            } else {
                total_damage += (b[i] / A + 1) * a[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (B - total_damage + a[i] > 0) {
                check = true;
                break;
            }
        }

        if (check) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
