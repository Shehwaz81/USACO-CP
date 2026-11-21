#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;

    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {cin >> h[i];}

    vector<ll> min_val(n + 1, LLONG_MAX); // for each size, what is the min asymmetry

    // start at the center, and extend each pointer
    for (int i = 0; i < n; i++) {

        // l == r in the beginning (odd)
        int l = i, r = i, s = 1;
        ll val = 0;
        while (l >= 0 && r < n) {
            val += abs(h[l] - h[r]);
            min_val[s] = min(min_val[s], val);

            s+=2;
            l--, r++;
        }


        // l = i, r = i + 1 (even)
        l = i, r = i + 1, s = 2;
        val = 0;
        while (l >= 0 && r < n) {
            val += abs(h[l] - h[r]);
            min_val[s] = min(min_val[s], val);

            s+=2;
            l--, r++;
        }
    }

    // print
    for (int i = 1; i <= n; i++) {
        cout << min_val[i] << ' ';
    }
    cout << '\n';
}