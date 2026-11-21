#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> t(n), b(n);
    for (int i = 0; i < n; i++) {cin >> t[i];}
    for (int i = 0; i < n; i++) {cin >> b[i];}

    int ans = 0;
    // calc top
    for (int i = 0; i < n; i++) {
        if (t[i]) {ans += 3;}
        if (t[i] && i > 0 && t[i - 1]) {ans -= 2;}
    }

    // calc bottom
    for (int i = 0; i < n; i++) {
        if (b[i]) {ans += 3;}
        if (b[i] && t[i] && i % 2 == 0) {ans -= 2;} // if the top is also wet and the index is even
        if (b[i] && i > 0 && b[i - 1]) {ans -= 2;}
    }

    cout << ans << endl;
}