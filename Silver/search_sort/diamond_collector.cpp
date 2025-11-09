#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    sort(a.begin(), a.end());

    vector<int> fit_diamonds_from(n);
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && a[r] - a[l] <= k) r++;
        fit_diamonds_from[l] = r - l;
    }
    
    vector<int> max_val_after(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        max_val_after[i] = max(max_val_after[i + 1], fit_diamonds_from[i]);
    }
    // calc max possible value of 2 cases
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, fit_diamonds_from[i] + max_val_after[i + fit_diamonds_from[i]]);
    }
    cout << ans << endl;
}