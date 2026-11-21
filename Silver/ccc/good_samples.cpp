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
    ll n, m, k; cin >> n >> m >> k;
    
    if (n > k) {cout << -1 << endl; return 0;}
    if (m == 1 && n != k) {cout << -1 << endl; return 0;}
    
    // no matter what, the minimum k is always = n (if all ints are same), so we start 
    // with that
    ll curr_k = n;
    vector<ll> a(n, 1);
    
    // start at second, as doing something to the first doesn't change anything
    ll c = 1, prev = 1, window = 1;
    for (int i = 1; i < n; i++) {
        if (curr_k == k) {
            a[i] = prev;
            continue;
        }
        if (curr_k > k) {cout << -1 << endl; return 0;}
        
        if (curr_k + c <= k && window < m) {
            // set this element to the prev_num + 1
            a[i] = ++prev;
            
            // add the contribution
            curr_k += c;
            
            // update contribution and window size
            c++, window++;
        } else if (curr_k + c <= k && window == m) {
            // set this element to the number that will contribute the most good samples
            // this number is the last number before any number is repeated
            // we do this by subtracting window size
            int optimal = a[i - window];
            a[i] = optimal;
            prev = a[i];
            
            // add the contribution
            curr_k += c - 1; // we do -1 as c is meant to represent contribution if we did the next number or window size (m + 1), this is just window size m, so the expected contribution is c - 1
        } else if (curr_k + c > k) {
            // we need to find the element that is i - (k - curr_k) elements away, as set 
            // it equal to that, so it contributes exactly 1 to the amt of good samples
            int need = k - curr_k;
            a[i] = a[i - need - 1];
            prev = a[i];
            
            // add need amt to curr_k;
            curr_k += need;
        }
    }
    
    // print ans
    if (curr_k != k) {cout << -1 << endl; return 0;}
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}