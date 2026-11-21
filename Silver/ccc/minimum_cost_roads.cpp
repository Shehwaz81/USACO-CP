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

struct edge {
    int a, b, l, c;
    bool operator<(const edge e) const {
        if (l != e.l) return l < e.l;
        return c < e.c;
    }
};

int n, m;

vector<ll> parent, si;

int f(ll a) {
    while (parent[a] != a) {a = parent[a];}
    return a;
}

bool same(ll a, ll b) {
    return f(a) == f(b);
}

void unite(int a, int b) {
    a = f(a);
    b = f(b);
    if (si[a] < si[b]) {swap(a, b);}
    parent[b] = a;
    si[a] += si[b];
}


vector<vector<pair<int, int>>> adj;

void dijk(int s, vector<ll>& min_l) {

    using pll = pair<ll, ll>;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    min_l[s] = 0;
    pq.push({0, s});
    while (pq.empty() == false) {
        ll curr_node = pq.top().second, curr_len = pq.top().first;
        pq.pop();

        if (min_l[curr_node] < curr_len) {continue;}

        for (auto &[child, len] : adj[curr_node]) {
            ll tot_len = len + curr_len;

            if (min_l[child] > tot_len) {
                min_l[child] = tot_len;
                pq.push({tot_len, child});
            }
        }
    }
}



int main() {
    cin >> n >> m;
    
    // initialize kruskals
    parent.resize(n + 1, 0), si.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        // initially, all sets are disjoint (n sets)
        parent[i] = i;
    }

    // iniitialize edges (kruskals)
    vector<edge> edges(m);
    map<pair<int, int>, int> min_dist;

    for (int i = 0; i < m; i++) {
        int l;
        cin >> edges[i].a >> edges[i].b >> edges[i].l >> edges[i].c;

        if (min_dist.count({edges[i].a, edges[i].b}) == 0) {
            min_dist[{edges[i].a, edges[i].b}] = edges[i].l;
        } else {
            min_dist[{edges[i].a, edges[i].b}] = min(min_dist[{edges[i].a, edges[i].b}], edges[i].l);
        }

    }
    sort(edges.begin(), edges.end());


    // init dijk adj
    adj.resize(n + 1);

    ll min_cost = 0;
    for (auto &[a, b, l, c] : edges) {
        // check if they are NOT in the same component, and if the length is optimal (always connect)
        if (!same(a, b) && l == min_dist[{a, b}]) {
            unite(a, b);
            min_cost += c;
            
            // add edge to adj for dijk
            adj[a].push_back({b, l});
            adj[b].push_back({a, l});

        } else if (same(a, b)) {
            // run dijk
            vector<ll> min_l(n + 1, 1e15);
            dijk(a, min_l);

            // see if min curr length is <= what is required, if not, add the edge to adj and update min_cost
            if (min_l[b] > min_dist[{a, b}]) {
                min_cost += c;
                adj[a].push_back({b, l});
                adj[b].push_back({a, l});
            }
        }
    }

    cout << min_cost << endl;
}