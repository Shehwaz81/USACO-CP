#include <algorithm>
#include <vector>
#include <iostream>
#define all(x) (x).begin(), x.end()
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> cities(n), towers(m);
    for (int &city : cities) {cin >> city;}
    for (int &tower : towers) {cin >> tower;}
    sort(all(towers));
    vector<int> rtowers = towers;
    sort(rtowers.rbegin(), rtowers.rend());
    // for each city, take the minimum distance of left tower vs right tower using lower_bound
    int min_amt = 0;
    for (int i = 0; i < n; i++) {
        int val = cities[i], dist1, dist2;
        auto lower = lower_bound(all(towers), val);
        auto rlower = lower_bound(all(rtowers), val, [](const int &x, const int &y) {return x > y;});

        dist1 = (lower == towers.end() ? INT_MAX : abs(*lower - val));
        dist2 = (rlower == rtowers.end() ? INT_MAX : abs(*rlower - val));

        min_amt = max(min_amt, min(dist1, dist2));
    }
    cout << min_amt << endl;

}