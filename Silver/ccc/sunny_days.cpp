#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <cctype>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<bool> sunny(n);
    int p_freq = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'S') {sunny[i] = true;}
        else {sunny[i] = false; p_freq++;}
    }

    if (p_freq == 0) {
        cout << n - 1 << endl;
        return 0;
    }

    // two pointers
    int l = 0, p_cnt = 0, best = 0;
    for (int r = 0; r < n; r++) {
        if (!sunny[r]) {
            p_cnt++;
            while (l < r && l < n && p_cnt > 1) {
                if (!sunny[l++]) p_cnt--;
            }
        }
        best = max(best, r - l + 1);
    }

    cout << best << endl;
}