#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
// Using long double for better precision, though double is usually sufficient
using ld = long double;

vector<int> x, v;

bool poss(ld seconds) {
    int n = x.size();
    ld common_L = -1e18; 
    ld common_R = 1e18; 
    bool poss = true;
    for (int i = 0; i < n; i++) {
        ld d_low = x[i] - (v[i] * seconds);
        ld d_high = x[i] + (v[i] * seconds);
        
        common_L = max(d_low, common_L);
        common_R = min(d_high, common_R);
        
        if (common_L > common_R) {return false;}
    }
    return true;
}

int main() {
    int n; cin >> n;

    x.resize(n), v.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    // Binary Search on Time
    ld low = 0, high = 1e9 + 7;

    while (high - low > 10e-7) {
        ld mid = low + (high - low) / 2;
        if (poss(mid)) {
            high = mid; 
        } else {
            low = mid; 
        }
    }

    cout << high << endl;

    return 0;
}