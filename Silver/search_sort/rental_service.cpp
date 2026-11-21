#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define all(x) (x).begin, (x).end()
using ll = long long;

struct shop {
    ll g, c;
    // sort by decreasing cash or increasing gallons
    bool operator<(const shop& s) const {
        if (c != s.c) {return c > s.c;}
        return g < s.g;
    }
};


int main() {
    ll n, m, r; cin >> n >> m >> r;
    
    // input and sort cows desc order
    vector<ll> cow(n), pref_cows(n + 1);
    for (ll i = 0; i < n; i++) {cin >> cow[i];}
    sort(cow.rbegin(), cow.rend());
    for (ll i = 1; i <= n; i++) {pref_cows[i] += pref_cows[i - 1] + cow[i - 1];}
    
    // take in shop offers and sort
    vector<shop> store(m);
    vector<ll> pref_stores(n + 1, 0);
    for (ll i = 0; i < m; i++) {cin >> store[i].g >> store[i].c;}
    sort(store.begin(), store.end());
    // for i number of cows milked, how much money can we make?
    int idx = 0;
    for (ll i = 1; i <= n; i++) {
        // g is the gallon increase from prev
        ll g = pref_cows[i] - pref_cows[i - 1];
        ll curr_amt = pref_stores[i - 1];
        while (g > 0 && idx < m) {
            if (g >= store[idx].g) {
                curr_amt += store[idx].c * store[idx].g;
                g -= store[idx].g;
                store[idx].g = 0;
                idx++;
            } else {
                curr_amt += store[idx].c * g;
                store[idx].g -= g;
                g = 0;
            }
        }
        pref_stores[i] = curr_amt; // curr_amt includes prev prefix sum, see above
    }
    
    // take in rent offers
    vector<ll> rent(r), pref_rent(n + 1, 0);
    for (ll i = 0; i < r; i++) {cin >> rent[i];}
    sort(rent.rbegin(), rent.rend());
    // make pref sum for i number of cows not milked
    for (ll i = 1; i <= n; i++) {
        pref_rent[i] = pref_rent[i - 1];
        if (i - 1 < r) pref_rent[i] += rent[i - 1];
    }
    
    // find the max by "turning the knob"
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll curr = pref_stores[i] + pref_rent[n - i];
        ans = max(ans, curr);
    }
    cout << ans << endl;
    
    
}