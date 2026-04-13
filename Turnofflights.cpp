#include <iostream>
using namespace std;

bool canTurnOff(string &bulbs, int n, int k, int L) {
    int operations = 0;

    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            operations++;
            i += L;  // cover L bulbs
        } else {
            i++;
        }
    }

    return operations <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller L
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}