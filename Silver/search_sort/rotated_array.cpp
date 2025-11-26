#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

// This works for only distinct elements, if it is not distinct, then you must 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // binary search
    int l = 0, r = n - 1, ans = INT_MAX;
    while (l <= r) {
        int mid = l + (r - l)/2;
        if (a[mid] > a[r]) {
            // move to right
            l = mid + 1;
        } else {
            ans = min(a[mid], ans);
            r = mid - 1;
        }
    }
    cout << ans << endl;
}