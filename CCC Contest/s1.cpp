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
    ll a, b, k, t; cin >> a >> b >> k >> t;

    ll dist = abs(b - a);
    if (dist == 0) {
        if (t == 1) cout << 0 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll big_hops = dist / k, leftover = dist % k;

    // calculate if you stop short of big hops
    ll leftover_left = leftover + k;
    ll tot_left = leftover_left + (big_hops - 1);
    if (big_hops == 0) {tot_left += 2;}

    // calc if you were to go one k hop over
    ll dist_over = dist - leftover + k;
    ll leftover_right = dist_over - dist;
    ll tot_right = leftover_right + big_hops + 1;

    // find dist normally
    ll tot_norm = big_hops + leftover;

    set<ll> poss;
    poss.insert(tot_left);
    poss.insert(tot_right);
    poss.insert(tot_norm);
    poss.insert(tot_norm + 2); // also a possibility
    poss.insert(tot_right + 2);

    if (t == 1) {
        cout << *(poss.begin()) << endl;
    } else {
        cout << *(++poss.begin()) << endl;
    }
}