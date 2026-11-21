#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    int n, l, q; cin >> n >> l >> q;
    
    vector<int> diff(n + 2, 0);

    for (int i = 0; i < l; i++) {
        int p, s; cin >> p >> s;

        int left = max(0, p - s);
        int right = min(n, p + s);

        diff[left] += 1, diff[right + 1]  -= 1;
    }

    // compute difference array int new array;
    vector<int> a(n + 1, 0);
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += diff[i];
        a[i] = sum;
    }

    while (q--) {
        int m; cin >> m;
        if (a[m] > 0) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}