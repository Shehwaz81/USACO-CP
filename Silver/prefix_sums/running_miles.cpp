#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {cin >> b[i];}
        // calc contribution of each element if it were a suffix or prefix
        vector<int> prefix(n), suffix(n);
        for (int i = 0; i < n; i++) {
            prefix[i] = b[i] + i;
            suffix[i] = b[i] - i;
        }
        
        // calc what is the max contribution of the suffix you can have, and whats the max contribution of the prefix you can have
        for (int i = 1; i < n; i++) {prefix[i] = max(prefix[i], prefix[i - 1]);}
        for (int i = n - 2; i >= 0; i--) {suffix[i] = max(suffix[i], suffix[i + 1]);}
        
        // for each middle term, calculate the max suffix and prefix (b1 and b3) it can have
        // also make sure that the middle b (b2), is in between the first and last element, as we need at least 3 elements for a valid result, and to get a valid suffix + prefix, we need to make b2 in between but not equal to the first and last element, so that we can actually calculate b3 and b1 in the extremes
        int best = 0;
        for (int i = 1; i < n - 1; i++) {
            int contr = b[i];
            contr += prefix[i - 1];
            contr += suffix[i + 1];
            best = max(contr, best);
        }
        cout << best << endl;
    }
}