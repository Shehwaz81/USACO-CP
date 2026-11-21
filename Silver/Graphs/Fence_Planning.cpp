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
vector<pair<ll,ll>> pos;
map<int,vector<int>> adj;
ll max_x = -1, max_y = -1, min_x = INT_MAX, min_y = INT_MAX;

void dfs(int s) {
    visited[s] = true;
    max_x = max(pos[s].first, max_x), max_y = max(pos[s].second, max_y);
    min_x = min(pos[s].first, min_x), min_y = min(pos[s].second, min_y);
    for (int & child : adj[s]) {
        if (!visited[child]) {dfs(child);}
    }
}

int main() {
    int n, m; cin >> n >> m;
    visited.resize(n + 1, false), pos.resize(n + 1);
    // store coordinates:
    for (int i = 1; i <= n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }
    // adj matrix
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // calc perimeter for each component
    ll min_perimeter = 5e10;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {continue;}
        dfs(i);
        // it is poss for fence to have 0 height or width
        ll perimeter = (long)(max_x - min_x) + (max_y - min_y);
        perimeter *= 2;
        min_perimeter = min(perimeter, min_perimeter);
        // reset variables
        max_x = -1, max_y = -1, min_y = INT_MAX, min_x = INT_MAX;
    }
    cout << min_perimeter << endl;
    
}