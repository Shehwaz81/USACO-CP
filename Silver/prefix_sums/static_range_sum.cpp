#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {cin >> a[i]; a[i] += a[i - 1];}
    // get all answers
    while (q--) {
        long long k, r; cin >> k >> r;
        // answer is just the sum at point R - sum at point K. 0 represents when you want to start from the begining, so a[0] would be 0, and so the answer would just be a[r]
        long long ans = (long long)a[r] - a[k];
        cout << ans << endl;
    }
}