#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<pair<ll, ll>> deals(n);

    ll init = 1, a;
    cin >> a;
    deals[0] = {init, a};
    for (int i = 2; i <= n; i++) {
        init *= 2;
        cin >> a;
        deals[i - 1] = {init, a};
    }

    sort(deals.begin(), deals.end(), [&] (const pair<int,int> i, const pair<int, int> j) {
        return (i.second / i.first) < (j.second / j.first);
    });

    while (q--) {
        ll v; cin >> v;

        ll cost = 0;

        ll min_cost = LLONG_MAX, curr_cost = 0, curr_v = v;
        for (int i = 0; i < n; i++) {
            if (v - deals[i].first < 0) {
                min_cost = min(min_cost, deals[i].second);
            } else {
                curr_cost += (curr_v / deals[i].first) * deals[i].second;
                curr_v = v % deals[i].first;
                if (curr_v != 0) {
                    min_cost = min(min_cost, curr_cost + deals[i].second);
                }
            }

            if (curr_v == 0) {
                min_cost = min(curr_cost, min_cost);
                break;
            }
        }
        cout << min_cost << endl;
    }
}