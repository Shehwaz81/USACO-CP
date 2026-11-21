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
using p = pair<ll, ll>;

vector<vector<p>> adj;
vector<bool> visited;
vector<ll> dist;
priority_queue<p, vector<p>, greater<p>> pq; // sort by least weighted edges
set<int> min_dur;


void dijk(int s) {
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        
        ll curr_node = pq.top().second, w = pq.top().first;
        pq.pop();
        if (visited[curr_node]) {continue;}
        visited[curr_node] = true;
        
        for (auto &[child, child_w] : adj[curr_node]) {
            
            ll curr_dist = dist[curr_node] + child_w;
            if (curr_dist < dist[child]) {
                dist[child] = curr_dist;
                pq.push({curr_dist, child});
            }
        } 
    }
}

int main() {
    int n, m; cin >> n >> m;
    
    visited.resize(n + 1, false), adj.resize(n + 1), dist.resize(n + 1, 1e16);
    
    for (int i = 0; i < m; i++) {
        int c1, c2, d; cin >> c1 >> c2 >> d;
        
        // store duration and flight connections
        adj[c1].push_back({c2, d});
    }
    
    dijk(1);
    
    for (int i = 0; i < n; i++) {
        cout << dist[i + 1] << ' ';
    }
    cout << endl;
}