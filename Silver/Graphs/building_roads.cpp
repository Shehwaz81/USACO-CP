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

void dfs(int s) {
    visited[s] = true;
    for (int & child : adj[s]) {
        if (!visited[child]) {
            visited[child] = true; // you can remove this as it is handled by the next fucntion call
            dfs(child);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> connected;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected.push_back(i);
            dfs(i);
        }
    }
    int s = connected.size();
    cout << s - 1 << endl; // 1 less road is needed than amt of connected components
    if (s == 1) {return 0;}
    for (int i = 0; i < s - 1; i++) {
        cout << connected[i] << ' ' << connected[i + 1] << endl;
    }
}