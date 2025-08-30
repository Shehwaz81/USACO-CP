#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> cows(n);
    for (int & i : cows) cin >> i;
    sort(all(cows));
    // calc max for each possible haybal touched first
    int best = 0;
    for (int i = 0; i < n; i++) {
        int prev = cows[i], index = i, blast = 1, counter = 1, curr;
        // break it up into left and right, first calc right explo.
        while (true) {
            curr = prev;
            for (int j = index + 1; j < n; j++) {
                if ((prev + blast) >= cows[j] && cows[j] >= cows[i]) {
                    curr = cows[j];
                    index = j;
                    counter++;
                } else {break;}
            }
            if (curr == prev) break;
            prev = curr;
            blast++;
        }
        // reset vars and calc left side
        prev = cows[i], index = i, blast = 1;
        while (true) {
            curr = prev;
            for (int j = index - 1; j >= 0; j--) {
                if ((prev - blast) <= cows[j] && cows[j] <= cows[i]) {
                    curr = cows[j];
                    index = j;
                    counter++;
                } else {break;}
            }
            if (curr == prev) break;
            prev = curr;
            blast++;
        }
        best = max(counter, best);
    }
    cout << best << endl;
    
    

    return 0;
}