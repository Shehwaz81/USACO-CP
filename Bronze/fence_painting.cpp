#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;


int main() {
    vector<bool> colored(101, false);
    int a, b; cin >> a >> b;
    for (int i = a + 1; i < b; i++) {colored[i] = true;}
    int c, d; cin >> c >> d;
    for (int i = c; i <= d; i++) {colored[i] = true;}
    int ans = 0;
    for (int i = 0; i < 101; i++) {ans += colored[i];}
    cout << ans << endl;
}
