#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll,ll>;

struct edge {
    ll n, t, h;

    bool operator<(const edge& e) const {
        // we have to do x > e.x as we will use a pq
        if (t != e.t) return t > e.t;
        return h > e.h;
    }
};

int main() {
    int k, n, m; cin >> k >> n >> m;
    vector<vector<edge>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, t, h; cin >> a >> b >> t >> h;

        // 2 way edges
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    int a, b; cin >> a >> b;

    priority_queue<edge> pq;
    vector<vector<ll>> t(n + 1, vector<ll>(200, LLONG_MAX)); // first idx is node, second is the hull, the value is the shortest time 
    t[a][0] = 0;
    pq.push({a, 0, 0});

    while (pq.empty() == false) {
        ll curr_node = pq.top().n, curr_hull = pq.top().h, curr_time = pq.top().t;
        pq.pop();
        
        if (curr_hull >= k || t[curr_node][curr_hull] < curr_time) {continue;}
        for (auto &[node, time, hull] : adj[curr_node]) {
            ll new_time = time + curr_time;
            ll new_hull = hull + curr_hull;
            if (new_hull < k && t[node][new_hull] > new_time) {
                t[node][new_hull] = new_time;
                pq.push({node, new_time, new_hull});
            }
        }
    }

    ll best = *min_element(t[b].begin(), t[b].end());
    cout << (best == LLONG_MAX ? -1 : best) << endl;
}