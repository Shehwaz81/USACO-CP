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

vector<int> a, b;

int main() {
    int n; cin >> n;

    // populate a and b
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    for (int i = 0; i < n; i++) {cin >> b[i];}

    // see if b with all adjacent same elements removed (simulated) is a subsequence of a
    int b_ptr = 0;
    for (int a_ptr = 0; a_ptr < n; a_ptr++) {
        if (b_ptr == n) {break;}
        
        // if it is equal to a[i], increment to the next element that is not ajacent and same to any before.
        if (a[a_ptr] == b[b_ptr]) {
            int prev = b[b_ptr++];
            while (b_ptr < n && prev == b[b_ptr]) {b_ptr++;}
        }
    }

    // if bp is NOT a subsequence of a, then swiping to create a -> b is NOT possible
    if (b_ptr != n) {
        cout << "NO" << endl;
        return 0;
    }

    // now since we have established that its possible, we use two pointer get all swipes required
    vector<pair<int, int>> swipes_r, swipes_l;
    int j = 0; // for array b
    for (int i = 0; i < n; i++) { // i is for array a
        if (a[i] != b[j]) {continue;}

        // if they are equal, that means we must swipe. 

        // case 1: if j < i, then we do a left swipe [j, i]
        if (j < i) {
            swipes_l.push_back({i, j}); // sort by right enpoint
        }

        // increment j until b[i] != a[i], and then check if j > i. If true, then we must swipe to right
        while (j < n && b[j] == a[i]) {j++;}
        j -= 1;
        
        if (j > i) {
            swipes_r.push_back({i, j}); // sort by left endpoint
        }

        j++; // we want to move to the next element of b, as this one is already good
    }
    sort(swipes_l.begin(), swipes_l.end()); // increasing right endpoint 
    sort(swipes_r.rbegin(), swipes_r.rend()); // decreasing left endpoint

    cout << "YES" << endl;
    cout << swipes_r.size() + swipes_l.size() << endl;
    for (auto &[r, l] : swipes_l) {
        cout << 'L' << ' ' << l << ' ' << r << endl;
    }
    for (auto &[l, r] : swipes_r) {
        cout << 'R' << ' ' << l << ' ' << r << endl;
    }


}