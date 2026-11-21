#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using ld = long double;

int main() {
    int n; cin >> n;
    vector<pair<int ,int>> o;
    for (int i = 0; i <n ; i++) {
        int t, p; cin >> t >> p;
        o.push_back({t, p});
    }
    sort(o.begin(), o.end());
    
    int pt = o[0].first, pp = o[0].second;
    ld ans = 0;
    for (int i = 1; i < n; i++) {
        ld ms = (float)abs(pp - o[i].second) / (float)(o[i].first - pt);
        ans = max(ms, ans);
        
        pt = o[i].first, pp = o[i].second;
    }
    cout << ans << endl;
}