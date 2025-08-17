#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
    int n; cin >> n; // as n is small enough max value for int
    vector<ll> cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i];
    sort(all(cows));
    ll max_t = 0;
    ll amt = 0;
    for (int i = 0; i < n; i++) {
        int t = (cows[i] * (n - i));
        if (max_t < t) {max_t = t; amt = cows[i];}
    }
    cout << max_t << ' ' << amt << endl;
}