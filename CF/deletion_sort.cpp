#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

bool nd(int n, vector<int> a) {
    if (n == 1) {return true;}

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {return false;}
    }

    return true;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {cin >> a[i];}

        if (nd(n, a)) {
            cout << n << endl;
        } else {
            cout << 1 << endl;
        }
    }
}