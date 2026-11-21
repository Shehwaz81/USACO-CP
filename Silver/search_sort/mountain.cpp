#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    if (n == 1) {cout << a[0] << endl; return 0;}
    // binary search
    int l = 0, r = n - 1, ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid == 0 && a[mid] > a[mid + 1]) {ans = a[0]; break;}
        else if (mid == 0) {l = mid + 1;}
        else if (a[mid] > a[mid - 1]) {ans = a[mid]; l = mid + 1;}
        else {r = mid - 1;}
    }
    cout << ans << endl;
}