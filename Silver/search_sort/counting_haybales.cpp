#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n, q; cin >> n >> q;
    vector<int> a;
    for (int i = 0; i < n; i++) {int val; cin >> val; a.push_back(val);}
    sort(a.begin(), a.end());
    // for each query:
    while (q--) {
        int A, B; cin >> A >> B;
        auto lower = lower_bound(a.begin(), a.end(), A);
        auto upper = upper_bound(a.begin(), a.end(), B);
        if (lower == a.end() || * lower > B) {cout << 0 << endl; continue;}
        cout << upper - lower << endl;
    }
}
