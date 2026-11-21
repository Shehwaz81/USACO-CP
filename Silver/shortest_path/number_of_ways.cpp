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


int countPaths(int n, vector<vector<int>>& roads) {

    int s = roads.size();
    vector<vector<pair<int,int>>> adj(n);

    for (auto & i : roads) {
        int u = i[0], v = i[1], t = i[2];
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    using p = pair<ll,ll>;
    priority_queue<p, vector<p>, greater<p>> pq;

    vector<ll> dist(n, LLONG_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    ll m = 1e9 + 7;
    while (!pq.empty()) {
        ll cn = pq.top().second, cd = pq.top().first; 
        pq.pop();

        // if the current distance is MORE than the previous, optimal distance, then there is no way that 
        // this can be a possible shortest path
        if (dist[cn] < cd) {continue;}

        dist[cn] = cd;
        for (auto &[n, d] : adj[cn]) {
            ll nd = cd + d;
            if (dist[n] > nd) {
                dist[n] = nd;
                ways[n] = ways[cn];
                pq.push({nd, n}); // DISTANCE FIRST, NODE SECOND
            } else if (dist[n] == nd) {
                ways[n] += ways[cn];
                ways[n] = ways[n] % m;
            }
        }
    }
    return ways[n - 1];
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> road(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> road[i][0] >> road[i][1] >> road[i][2];
    }

    ll ans = countPaths(n, road);
    cout << ans << endl;
}