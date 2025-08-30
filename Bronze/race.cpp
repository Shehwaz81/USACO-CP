#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end();
using namespace std;

int main() {
    int k, n; cin >> k >> n;
    while (n--) {
        int x; cin >> x;
        int currDist = 0, slowDist = 0, t = 0;
        // start at t = 0 as when t = 1, you must have travelled 1 unit
        for (int currSpeed = 1;; currSpeed++) { // loop infinitely until interference
            currDist += currSpeed;
            t++;
            if (currDist + slowDist >= k) {cout << t << endl; break;}
            // is current speed above or equal to x? if it is we must add that to our slowing down distance, as for us to reach down to speed x, we would require slowDist amt of distance
            if (currSpeed >= x) {
                slowDist += currSpeed;
                // it would also take 1 second of time to slow down per increment of currSpeed
                t++;
                // check again if we have reached the finish line
                if (currDist + slowDist >= k) {cout << t << endl; break;}
            }
        }
    }
}