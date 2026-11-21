#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using ll = long long;

map<int, vector<int>> adj;
vector<bool> visited;
queue<int> q;
vector<int> team; // 0 is team 1, 1 is team 2.

bool bfs(int s, bool t) {
    visited[s] = true;
    team[s] = t;
    q.push(s);
    // start bfs
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int & child : adj[curr]) {
            if (!visited[child]) q.push(child);
            visited[child] = true;
            if (team[child] == team[curr]) {return false;}
            else {team[child] = (team[curr] == 1 ? 2 : 1);}
        }
    }
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    visited.resize(n + 1, 0), team.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool starting_team = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool result = bfs(i, starting_team);
            if (!result) {cout << "IMPOSSIBLE" << endl;}
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << team[i] << ' ';
    }
    cout << '\n';
    
}