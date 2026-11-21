#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using p = pair<int, int>;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    priority_queue<p, vector<p>, greater<p>> pq;

    vector<int> time(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<vector<p>> adj(n + 1);

    // store edges in adj list
    for (auto &edge : times) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    // dijkstras
    time[k] = 0;
    time[0] = 0;
    pq.push({0, k});
    while (!pq.empty()) {

        int curr_node = pq.top().second, curr_time = pq.top().first;
        pq.pop();

        if (curr_time > time[curr_node]) {continue;} // idk if its >= or >
        visited[curr_node] = true;

        // search children
        for (auto &[child, w] : adj[curr_node]) {
            int t = curr_time + w;

            if (t < time[child]) {
                time[child] = t;
                pq.push({t, child});
            }

        }
    }

    // now find maximum time out of all distances:

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return -1;
    }
    return *max_element(time.begin(), time.end());
}


int main() {
    int n, k; cin >> n >> k;
    int s; cin >> s;
    vector<vector<int>> times;
    for (int i = 0; i < s; i++) {
        int u, v, w; cin >> u >> v >> w;
        times.push_back({u, v, w});
    }
    
    cout << networkDelayTime(times, n, k) << endl;
}