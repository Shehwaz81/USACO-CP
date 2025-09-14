#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> cow(n);
        for (ll & c : cow) {cin >> c;}

        // see if you can get all hunger level same, and amt needed for it
        int bagAmt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cow[i + 1] > cow[i]) {
                // if the i+2th cow doesn't exist, then we cannot make i and i + 1 equal
                if (i + 2 >= n) {cout << -1 << endl; return 0;}
                ll diff = cow[i + 1] - cow[i];
                // you need diff * 2 bags as you are changing 2 cows "diff" times
                bagAmt += diff * 2;
                cow[i + 1] = cow[i];
                cow[i + 2] -= diff;
            } else if (cow[i] > cow[i + 1]) {

                if (i % 2 != 1) {cout << -1 << endl; return 0;}
                int cowAmt = i + 1, diff = cow[i] - cow[i - 1];
                // all previous cow pairs are garenteed to be adjacent because of other if statement
                bagAmt += diff * cowAmt;
            }
        }
        cout << bagAmt << endl;
    }
}