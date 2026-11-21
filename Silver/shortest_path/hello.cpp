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

struct edge{
    ll node, t, h;

    // sort for priority queue so that it is the MINIMUM pq of t
    bool operator<(const edge& e) const {
        return t > e.t;
    }
};

int main() {
    ll k, n, m; cin >> k >> n >> m;

    vector<vector<edge>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<ll> dist(n + 1, 2e9 + 7); // stores distance ONLY IF h < k
    
    for (ll i = 0; i < m; i++) {
        ll a, b, t, h; cin >> a >> b >> t >> h;

        // 2 way graph
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }

    // fetch the starting and ending nodes
    ll s, e; cin >> s >> e;

    // run the dijktras
    priority_queue<edge> pq;

    dist[s] = {0};
    pq.push({s, 0, 0});

    while (pq.empty() == false) {
        ll curr_node = pq.top().node, curr_time = pq.top().t, curr_h = pq.top().h;
        pq.pop();
        // update min distance vector if poss
        if (curr_time > dist[curr_node]) {continue;}
        if (curr_h < k) {dist[curr_node] = curr_time;}
        visited[curr_node] = true;
        
        for (auto e : adj[curr_node]) {
            ll time = curr_time + e.t;
            ll hull = curr_h + e.h;
            if (hull < k && time < dist[e.node]) {
                dist[e.node] = time;
                pq.push({e.node, time, hull});
            }
        }
    }
    
    // check ans
    if (!visited[e]) {cout << -1 << endl;}
    else {cout << dist[e] << endl;}
}
