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
using ld = long double;


int main() {
    int t; cin >> t;
    while (t--) {
        string num; cin >> num;
        int n = num.size();

        // check if this string is NOT already binary (1 and 0 only)
        bool binary = true;
        for (char c : num) {if (c != '0' && c != '1') {binary = false; break;}}

        // find the value of the binary
        ll val = 0, half_val, m = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int x = num[i] - '0';
            ll curr = (x % 2 == 0 ? 0 : 1);

            // since we cannot do val / 2 later, as we have taken the modulo of a big number, calculate the value inside the loop.
            // because of binary being base 2, we can set the second last operated number as half val, as the next one will just be (val * 2) and maybe + 1
            // the + 1 at the end doesn't matter, as we need the floor
            if (i == n - 1) {half_val = val;}

            // since binary is base 2, you times all previous values that we added by 2 (moving them up a place), and add the curr to the rightmost
            val = ((val * 2) + curr) % m;

        }

        ll ans = (val + half_val) % m;
        ans += (binary ? 0 : 1); // if the answer was NOT binary to begin with, add 1, as we would need that initially to start our val operation

        cout << ans << endl;
    }
}