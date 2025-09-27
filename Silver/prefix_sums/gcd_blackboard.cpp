#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    
    vector<ll> preGCD(n + 1, 0), sufGCD(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        preGCD[i] = gcd(preGCD[i - 1], a[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        sufGCD[i] = gcd(sufGCD[i + 1], a[i]);
    }
    
    ll best = 0;
    for (int i = 0; i < n; i++) {
        ll currGCD = gcd(preGCD[i], sufGCD[i + 1]);
        best = max(currGCD, best);
    }
    cout << best << endl;
}