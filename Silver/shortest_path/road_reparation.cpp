#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

vector<int> parent, s;
vector<bool> visited;
vector<vector<int>> adj;

struct edge {
    int a, b, c;
    
    // sort by cost acending
    bool operator<(const edge& e) const {
        return c < e.c;
    }
};

int find(int x) {
    while (parent[x] != x) {x = parent[x];}
    return x;
}

// checks if in same component
bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (s[b] > s[a]) {swap(a, b);}
    parent[b] = a;
    s[a] += s[b];
}

void dfs(int s) {
    if (visited[s]) {return;}
    visited[s] = true;

    for (auto child : adj[s]) {
        dfs(child);
    }
}

int main() {
    int n, m; cin >> n >> m;
    
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end());
    
    // initialize DSU
    parent.resize(n + 1), s.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {parent[i] = i;}
    
    adj.resize(n + 1), visited.resize(n + 1, false);
    // kruskals (and also add edges)
    long long min_cost = 0;
    for (auto e : edges) {
        if (!same(e.a, e.b)) {
            unite(e.a, e.b);
            min_cost += e.c;

            // push the edge for dfs later
            adj[e.a].push_back(e.b);
            adj[e.b].push_back(e.a);
        }
    }
    
    // check if all nodes are in one component
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << min_cost << endl;
}