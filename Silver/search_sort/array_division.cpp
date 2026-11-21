#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<int> a;

bool poss(ll x, int k) {
    ll curr_sum = 0, n = a.size(), subarray_amt = 1; 
    // start at 1 subarray as just the original array is also considered 1
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return false; // if this is true, we cannot have a maxiumum sum of all subarrays of x
        if (curr_sum + a[i] > x) {
            subarray_amt++;
            curr_sum = a[i];
            if (subarray_amt > k) {return false;}
        }
        else {curr_sum += a[i];}
    }
    return true;
}

int main() {
    int n, k; cin >> n >> k;
    a.resize(n);
    ll sum = 0;
    for (int &i : a) {cin >> i; sum += i;}
    ll mx = *max_element(a.begin(), a.end());
    int l = mx, r = sum;
    // we are doing a reverse way of the monotonic function lol
    while (l < r) {
        ll mid = l + (r - l) / 2; // NOT + 1, we are finding FIRST true.
        if (poss(mid, k)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
}