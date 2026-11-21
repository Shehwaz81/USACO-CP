#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;
using p = pair<int, int>;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) {cin >> i;}

    vector<int> x = a;
    sort(x.begin(), x.end());
    
    // see what is the minimum index that doesn't match and the maximum index that does not match
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != x[i]) {r = i;}
        if (a[i] != x[i] && l == -1) {l = i;}
    }
    
    // measure the distance to see if it is greater than k. If it is, than it is impossible to sort fully
    cout << (r - l > k ? "No" : "Yes") << endl;
}

