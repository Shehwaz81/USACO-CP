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
        else cout << 2 << endl;
        return 0;
    }

    ll bh = dist / k, leftover = dist % k;
    
    // probably optimal
    ll middle = bh + leftover;

    // to the right
    ll r_dist = bh*k + k;
    ll right = bh + 1 + (r_dist - dist);


    // to the left
    ll l_dist = bh*k - k;
    ll left = bh - 1 + (dist - l_dist);
    if (bh == 0) left += 2;

    set<ll> poss;
    poss.insert(middle);
    poss.insert(left);
    poss.insert(right);
    poss.insert(middle + 2);
    poss.insert(right + 2);
    poss.insert(left + 2);

    if (t == 1) cout << min({left, middle, right}) << endl;
    if (t == 2) {cout << *(++poss.begin()) << endl;}






}