#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using ll = long long;

int n = 0, m = 0;
vector<vector<pair<int, int>>> adj; // pair is {connected node, width of worm hole}
queue<int> q;

vector<int> bfs(int x) {
    vector<int> connected(n, -1);
    int curr_component = 0;
    for (int i = 0; i < n; i++) {
        if (connected[i] != -1) {continue;}
        q.push(i);
        while (q.empty() == false) {
            int curr = q.front(); q.pop();
            connected[curr] = curr_component;
            for (auto &[child, w] : adj[curr]) {
                if (connected[child] == -1 && w >= x) {
                    q.push(child);
                    connected[child] = curr_component; // we must do this so that the child does not get added again if we explore another child first
                }
            }
        }
        curr_component++;
    }
    return connected;
}

int main() {
    cin >> n >> m;
    vector<int> cows(n);
    adj.resize(n);
    // read pos of cows and check if they are already sorted
    bool sorted = true;
    for (int i = 0; i < n; i++) {
        cin >> cows[i]; cows[i]--;
        if (cows[i] != i) {sorted = false;}
    }
    // if the array is already sorted
    if (sorted) {
        cout << -1 << endl; return 0;
    }
    // read edges/connections
    int max_w = 0;
    for (int i = 0; i < m; i++) {
        int c1, c2, w; cin >> c1 >> c2 >> w;
        c1--, c2--;
        max_w = max(max_w, w);
        adj[c1].push_back({c2, w});
        adj[c2].push_back({c1, w});
    }
    // binary search
    int l = 0, h = max_w, ans = 0;
    while (l <= h) {
        int mid = (l + h) / 2;
        vector<int> connected = bfs(mid);
        
        bool poss = true;
        for (int i = 0; i < n; i++) {
            // if pos of cow i and the position cow i must be are not in the same component, it is not poss
            if (connected[i] != connected[cows[i]]) {poss = false; break;}
        }
        // now for the binary conditions
        if (poss) {
            l = mid + 1;
            ans = max(mid, ans);
        } else {h = mid - 1;}
    }
    cout << ans << endl;
}
