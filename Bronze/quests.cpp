#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> b(n), sum(n + 1);

        for (int i = 1; i <= n; i++) {cin >> sum[i]; sum[i] += sum[i - 1];}
        for (int i = 0; i < n; i++) {cin >> b[i];}

        int best = 0;
        int redoQuest = 0;
        for (int i = 1; i <= n; i++) {
            if (i > k) {break;}
            int exp = sum[i];
            redoQuest = max(redoQuest, b[i - 1]);
            exp += (k - i) * redoQuest;
            best = max(best, exp);
        }
        cout << best << endl;
    }
}