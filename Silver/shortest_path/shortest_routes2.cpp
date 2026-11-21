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
using p = pair<ll,ll>;

vector<vector<bool>> visited;
vector<vector<ll>> dist;
vector<vector<p>> adj;

priority_queue<p, vector<p>, greater<p>> pq;

void dijk(int s) {
    dist[s][s] = 0;
    pq.push({0, s});
    
    while (pq.empty() == false) {
        int curr_node = pq.top().second;
        ll curr_len = pq.top().first;
        pq.pop();
        
        if (curr_len > dist[s][curr_node]) {continue;}
        visited[s][curr_node] = true;
        
        for (auto [child, c] : adj[curr_node]) {
            ll len = curr_len + c;
            
            if (len < dist[s][child]) {
                dist[s][child] = len;
                pq.push({len, child});
            }
        }
    }
}

int main() {
    int n, m, q; cin >> n >> m >> q;
    
    visited.resize(n + 1, vector<bool>(n + 1, false));
    dist.resize(n + 1, vector<ll>(n + 1, 1e18));
    adj.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        // this is a 2 way graph, so add path to both nodes
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    // precompute all minimum distances for each starting node possible
    for (int i = 1; i <= n; i++) {
        dijk(i);
    }
    
    // proccess q queries
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        
        // check if they are apart of the same component
        if (!visited[a][b]) {cout << -1 << endl;}
        else {cout << dist[a][b] << endl;}
    }
}