#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

using ll = long long;

ll first_true(ll l, ll h, function<bool(ll)> f) {
    ll res = -1;
    while (l <= h) {
        ll mid = l + (h - l) / 2;
        if (f(mid)) {
            res = mid; // Store potential answer
            h = mid - 1; // Try to find something smaller
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    // Standard CP optimization
    ios::sync_with_stdio(0); cin.tie(0);

    ll x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    int n; 
    cin >> n;
    string s; 
    cin >> s;

    ll tot_y = 0, tot_x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') tot_y++;
        else if (s[i] == 'D') tot_y--;
        else if (s[i] == 'R') tot_x++;
        else if (s[i] == 'L') tot_x--;
    }

    // Use pair of ll to prevent overflow during calculations
    pair<ll, ll> start{x1, y1}, req{x2, y2};

    // 2. Search up to 2e14
    ll ans = first_true(0, 2e14, [&](ll x) {
        pair<ll, ll> curr_copy = start;
        
        curr_copy.first += (x / n) * tot_x;
        curr_copy.second += (x / n) * tot_y;

        for (int i = 0; i < (x % n); i++) {
            if (s[i] == 'U') curr_copy.second++;
            else if (s[i] == 'D') curr_copy.second--;
            else if (s[i] == 'R') curr_copy.first++;
            else if (s[i] == 'L') curr_copy.first--;
        }

        ll dist = abs(req.first - curr_copy.first) + abs(req.second - curr_copy.second);
        return dist <= x;
    });

    cout << ans << endl;
}