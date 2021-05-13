#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    int A[10010];

    A[0] = A[n] = n + 1;

    int low = 1, high = n, mid;

    while (low < high) {
        mid = (low + high) / 2;

        int val_mid, val_mid_1;
        
        cout << "? " << mid << endl;
        cout.flush();
        cin >> val_mid;

        cout << "? " << mid + 1 << endl;
        cout.flush();
        cin >> val_mid_1;

        if (val_mid < val_mid_1) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << "! " << low << endl;
    cout.flush();
    return 0;
}

