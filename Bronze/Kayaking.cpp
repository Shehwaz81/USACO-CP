#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int n; cin >> n;
    vector<int> w(n*2);
    for (int i = 0; i < n*2; i++) cin >> w[i];
    sort(all(w));
    // remove every poss pair and see which sum is highest;
    int best = INT_MAX;
    for (int i = 0; i < n * 2; i++) {
        for (int j = i + 1; j < n * 2; j++) {
            auto wcopy = w;
            wcopy.erase(wcopy.begin() + i), wcopy.erase(wcopy.begin() + j - 1);
            int sum = 0;
            for (int k = 0; k < (n * 2) - 2; k += 2) {
                sum += abs(wcopy[k] - wcopy[k + 1]);
            }
            best = min(best, sum);
        }
    }
    cout << best << endl;
}