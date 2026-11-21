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
    int a, b, w;
};

int main() {
    int n, m; cin >> n >> m;
    vector<edge> edges;
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    vector<int> dist(n + 1, 2e9 + 1);
    dist[1] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (auto [a, b, w] : edges) {dist[b] = min(dist[b], dist[a] + w);}
    }

    // detect negative edge
    for (auto [a, b, w] : edges) {
       //  ....
    }
}