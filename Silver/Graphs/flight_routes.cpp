#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<int> visited;
map<vector<int>, vector<int>> adj;
int city_amt = 0;

void dfs (int s, int dir) {
    visited[s] = true;
    city_amt++;
    for (auto & child : adj[{s, dir}]) {
        if (!visited[child]) {dfs(child, dir);}
    }
}

int main() {
    int n, m; cin >> n >> m;
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[{a, 0}].push_back(b); // G
        adj[{b, 1}].push_back(a); // G'
    }
    // see if node 1 can reach all other nodes (can[1][x] for graph G):
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {cout << "NO" << '\n' << 1 << ' ' << i << endl; return 0;}
    }
    // reset visited
    fill(visited.begin(), visited.end(), false);
    // see if all nodes can reach node 1 with reverse dir method (can[1][x] for graph G')
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {cout << "NO" << '\n' << i << ' ' << 1 << endl; return 0;} 
    }
    cout << "YES" << endl;
}
