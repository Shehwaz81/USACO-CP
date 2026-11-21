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
    int n, x; cin >> n >> x;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {cin >> a[i];}
    sort(a.begin(), a.end());
    
    // two pointer to pair the smallest with the largest poss
    int r = n - 1, l = 0, amt = 0;
    // no matter what
    while (l <= r) {
        if (a[r] + a[l] <= x) {l++;}
        amt++;
        r--;
    }
    cout << amt << endl;
}