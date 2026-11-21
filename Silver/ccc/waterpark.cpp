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
    int n; cin >> n;

    vector<vector<int>> adj(n + 1);
    set<int> slides;
    while (true) {
        int x, y; cin >> x >> y;

        if (x == 0 && y == 0) break;


        // x < y, and it is a directed graph
        adj[x].push_back(y);

        // insert into set to go through later
        slides.insert(x);
        slides.insert(y);
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1; // base case

    for (int x : slides) {
        // search through all edges of slide x
        for (int y : adj[x]) {
            dp[y] += dp[x];
        }
    }

    cout << dp[n] << endl;
}