#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;

struct edge {
    ll n, c, l;
    bool operator<(const edge& e) const {
        // because we want pq to sort by least on top, 
        // c < e.c would make it sort top to bottom greatest to least
        return c > e.c; 
    }
};

int n, m;
ll ans = LLONG_MAX;
vector<bool> visited;
vector<vector<p>> adj;
void dfs(int s, ll curr_lvl, ll curr_cost) {
    if (s == n) ans = min(ans, curr_cost);
    if (visited[s]) {return;}
    visited[s] = true;


    for (auto &[child, lvl] : adj[s]) {
        int cost = abs(lvl - curr_lvl);
        dfs(child, lvl, cost + curr_cost);
    }
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // undirected graph
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    if (m == n - 1) { // do dfs in this case;
        visited.resize(n + 1, false);
        dfs(1, 0, 0);
        cout << ans << endl;
        return 0;
    }

    priority_queue<edge> pq;
    // track all poss costs AND chilling levels for each node
    vector<vector<ll>> cost(n + 1), lvl(n + 1); 

    cost[1].push_back(0);
    lvl[1].push_back(0);
    pq.push({1, 0, 0});

    while (pq.empty() == false) {
        ll curr_node = pq.top().n, curr_cost = pq.top().c, curr_lvl = pq.top().l;
        pq.pop();

        auto l = find(lvl[curr_node].begin(), lvl[curr_node].end(), curr_lvl);
        int idx = l - lvl[curr_node].begin();

        // check if this is a stale or unoptimal proccessing of a 
        // chilling level (if cost < curr_cost for the same chilling)
        if (l != lvl[curr_node].end() && cost[curr_node][idx] < curr_cost) {
            continue;
        }

        for (auto [node, chilling] : adj[curr_node]) {
            ll tot_cost = curr_cost + abs(curr_lvl - chilling);

            auto it = find(lvl[node].begin(), lvl[node].end(), chilling);
            if (it == lvl[node].end()) {
                lvl[node].push_back(chilling);
                cost[node].push_back(tot_cost);
                pq.push({node, tot_cost, chilling});
                continue;
            }

            int idx = it - lvl[node].begin();
            if (cost[node][idx] > tot_cost) {
                cost[node][idx] = tot_cost;
                lvl[node].push_back(chilling);
                cost[node].push_back(tot_cost);
                pq.push({node, tot_cost, chilling});
            }
        }
    }

    // find min ans for nth node
    cout << *min_element(cost[n].begin(), cost[n].end()) << endl;
}