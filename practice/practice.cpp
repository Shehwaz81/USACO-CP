#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;
using p = pair<int, int>;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        // assume undirected and unweighted graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    vector<int> dist(n + 1, -1);
    vector<bool> visited(n + 1, false);
    q.push(1);
    dist[1] = 0;
    visited[1] = true; 
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (auto child : adj[curr]) {
            if (!visited[child]) {
                dist[child] = dist[curr] + 1;
                q.push(child);
                visited[child] = true; 
            }
        }
    } 
}
