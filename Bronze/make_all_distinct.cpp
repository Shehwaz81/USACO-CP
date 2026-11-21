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


int main() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        map<ll, ll> freq;
        vector<ll> a(n);
        for (auto& i : a) {
            cin >> i;

            // if k is negative, we must flip all element signs so we can make k positive
            if (k < 0) {
                i *= -1;
                freq[i]++;
            }
        }
        k = abs(k); // change k into positive if it was negative

        // 2 distinct values can only equal each other at one point iff val1 % k = val2 % k; else, they will NOT be equal no matter how many times you add k
        for (int i = 0; i < n; i++) {

        }

    }
}