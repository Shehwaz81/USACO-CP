#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> sum(n + 1, 0);
    // we only need to know how far the sum of all id's are form being 7
    for (int i = 1; i <= n; i++) {
        cin >> sum[i]; 
        sum[i] += sum[i - 1];
        sum[i] = sum[i] % 7;
    }
    
    // compute prefix sum array, and use mod 7 to get what the values add up to relative to 7
    vector<int> first(7, -1);
    first[0] = 0;
    int best = 0;
    for (int i = 1; i <= n; i++) {
        if (first[sum[i]] == -1) {
            first[sum[i]] = i;
        } else {best = max(i - first[sum[i]], best);}
    }
    cout << best << endl;
}