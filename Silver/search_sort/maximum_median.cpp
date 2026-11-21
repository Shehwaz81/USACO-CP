#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

vector<int> a;

int lastTrue(int low, int high, function<bool(int)> f) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2; // + 1 bc we are rounding up (LAST true)
        if (f(mid)) {low = mid;}
        else {high = mid - 1;}
    }
    return low;
}

int main() {
    int n, k; cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    sort(a.begin(), a.end());
    cout << lastTrue(1, 2e9, [&](int x) {
        long long need = 0; // tracks how many operations are used
        int mid = (n - 1) / 2;
        for (int i = mid; i < n; i++) {
            need += max(0, x - a[i]);
        }
        return need <= k;
    }) << endl;
}