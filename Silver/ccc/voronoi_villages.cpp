#include <bits/stdc++.h>
using namespace std;
using d = double;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    d ans = 1e20; // inf
    // start at the second village, and end at the second last village to avoid out of bound
    // and to effectively calc windows
    d prev = v[0];
    for (int i = 1; i < n - 1; i++) {
        d l = (prev + v[i]) / 2.0;
        d r = (v[i] + v[i + 1]) / 2.0;
        
        ans = min(ans, r - l);
        prev = v[i];
    }
    
    cout << fixed << setprecision(1) << ans << endl;
}