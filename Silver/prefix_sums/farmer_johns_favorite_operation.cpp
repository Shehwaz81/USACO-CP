#include <bits/stdc++.h>
#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n), b(n * 2), pref((n * 2) + 1, 0);
        // store all numbers with the a[i] + m's to fully unrap the circle such that all distances are still there. 
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
            a[i] %= m;
        }
        sort(a.begin(), a.end());
k
        // make pref sum array
        for (int i = 1; i <= n * 2; i++) {
            pref[i] = pref[i - 1] + b[i - 1];
        }
        // calculate the minimum contribution per window of the fully unwrapped but intact circle
        ll best = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int l = i, r = i + n - 1;
            int k = l + (n - 1) /2; // median shifted by l, this is with 0 based indexing so it can actually work on our pref/suff - ix sums
            ll leftSum = pref[k] - pref[l]; // calc sum of all elements from the left side to k (not inclusive as the prefix sums are actually shifted + 1 because of the 0 in the beginning)
            ll leftSide = (k - l) * b[k] - leftSide; // subtract ls from the k contribution
            ll rightSum = pref[r + 1] - pref[k + 1] // calc sum of all elements from k (not inclusive since its in - pref[k + 1], so its apart of what we are subtracting), to r + 1 which just includes the final element r)
            ll rightSide = rightSum - (r - k) * b[k]; // subtract the contribution of k
            best = min(best, rightSide + leftSide); // add them up and get the max
        }
        cout << best << endl;
    }
}