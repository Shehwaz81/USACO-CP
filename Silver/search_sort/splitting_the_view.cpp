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

int n;
struct Cow {
    ll x, y;
    bool operator<(const Cow &c) const {
        return x < c.x;
    }
};

ll solve(vector<Cow>& cows) {
    // find the minimum and max/min Y for the PREFIX for index i
    vector<ll> min_pref(n, INT_MAX), max_pref(n, 0);
    // initialize starting values to build off of.
    min_pref[0] = cows[0].y;
    max_pref[0] = cows[0].y;
    // make rest of pref sum
    for (int i = 1; i < n; i++) {
        min_pref[i] = min(min_pref[i - 1], cows[i].y);
        max_pref[i] = max(max_pref[i - 1], cows[i].y);
    }
    
    // now make the suffix array with max/min Y for each index
    vector<ll> min_suff(n), max_suff(n);
    min_suff[n - 1] = cows[n - 1].y;
    max_suff[n - 1] = cows [n - 1].y;
    // make rest of suffix sum
    for (int i = n - 2; i >= 0; i--) {
        min_suff[i] = min(min_suff[i + 1], cows[i].y);
        max_suff[i] = max(max_suff[i + 1], cows[i].y); 
    }
    
    // calculate area for each index i, and keep track of the max area
    ll min_area = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (cows[i].x == cows[i + 1].x) {continue;} // means that they would be touching
        // calc box 1's area
        ll b1_h = max_pref[i] - min_pref[i];
        ll b1_w = cows[i].x - cows[0].x;
        ll b1_area = b1_h * b1_w;
        
        // calc box 2's area
        ll b2_h = max_suff[i + 1] - min_suff[i + 1];
        ll b2_w = cows[n - 1].x - cows[i + 1].x;
        ll b2_area = b2_h * b2_w;
        
        min_area = min(min_area, (b2_area + b1_area));
    }
    return min_area;
}

int main() {
    cin >> n;
    vector<Cow> cows(n);
    ll min_x = LLONG_MAX, max_x = 0, min_y = INT_MAX, max_y = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y; // first we will solve with x, after that with y
        min_x = min(min_x, cows[i].x);
        max_x = max(max_x, cows[i].x);
        min_y = min(min_y, cows[i].y);
        max_y = max(max_y, cows[i].y);
    }
    ll original = (max_x - min_x) * (max_y - min_y);
    
    sort(cows.begin(), cows.end());
    ll best_area = solve(cows);
    
    for (int i = 0; i < n; i++) {
        swap(cows[i].x, cows[i].y);
    }
    
    sort(cows.begin(), cows.end());
    best_area = min(best_area, solve(cows));
    cout << original - best_area << endl;

}