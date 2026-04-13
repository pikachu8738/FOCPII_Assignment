#include<iostream>
using namespace std;

const int MAXN = 10000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> distinctPrimeCount(MAXN + 1, 0);

    for (int i = 2; i <= MAXN; i++) {
        if (distinctPrimeCount[i] == 0) { 
            for (int j = i; j <= MAXN; j += i) {
                distinctPrimeCount[j]++;
            }
        }
    }

    vector<int> power2(25);
    power2[0] = 1;
    for (int i = 1; i < 25; i++) {
        power2[i] = power2[i - 1] * 2;
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = distinctPrimeCount[n];
        cout << power2[k] << '\n';
    }

    return 0;
}