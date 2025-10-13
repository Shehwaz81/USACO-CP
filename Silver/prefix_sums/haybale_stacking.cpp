#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n, 0), diff(n + 2, 0);
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    int rsum = 0;
    for (int i = 1; i <= n; i++) {
        rsum += diff[i];
        a[i - 1] += rsum;
    }
    sort(all(a));
    cout << a[n / 2] << endl;
}