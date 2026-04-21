#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& arr) {
    unordered_map<int, int> freq;

    // Step 1: count frequencies
    for (int x : arr)
        freq[x]++;

    vector<int> v;

    // Step 2: each value can be used at most twice
    for (auto &p : freq) {
        int val = p.first;
        int f = p.second;

        v.push_back(val); // first use
        if (f > 1)
            v.push_back(val); // second use
    }

    // Step 3: sort descending
    sort(v.rbegin(), v.rend());

    // Step 4: alternate picking
    long long alex = 0, bob = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0)
            alex += v[i];
        else
            bob += v[i];
    }

    return (alex > bob) ? "Alex" : "Bob";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(n, arr) << "\n";
    }
}