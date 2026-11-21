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
    ll n; cin >> n;
    
    vector<ll> a(n);
    ll best = -10e9, curr_sum = 0;
    for (ll i = 0; i < n; i++) {
        ll curr; cin >> curr;

        // if the current element is greater than the optimal sum of this point + curr, then there is no reason to keep the curr_sum, we can replace it with the new optimal
        curr_sum = max(curr, curr_sum + curr);

        best = max(curr_sum, best);
    }
    cout << best << endl;
}