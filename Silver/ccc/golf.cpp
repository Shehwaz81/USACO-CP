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

const int INF = 1e9;

int main() {
    int d, n; cin >> d >> n;
    
    vector<int> clubs(n);
    for (int& c : clubs) {cin >> c;}

    // initiallize dp
    vector<int> dp(d + 1, INF);
    dp[0] = 0; // base case;
    for (int i = 1; i <= d; i++) {
        for (int c : clubs) {
            if (i - c < 0) {continue;} // not possible if its less than 0;
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    if (dp[d] == INF) {
        cout << "Roberta acknowledges defeat." << endl;
    } else {
        cout << "Roberta wins in " << dp[d] << " strokes." << endl;
    }
}