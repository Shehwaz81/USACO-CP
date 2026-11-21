#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

map<pair<int,int>, vector<pair<int,int>>> adj; // stores roads
queue<pair<int,int>> q;
vector<vector<bool>> visited;
int n, k, r;

vector<int> dy = {0, 0, 1, -1}, dx = {1, -1, 0, 0};

void bfs(pair<int,int> s) {
    q.push(s);
    visited[s.first][s.second] = true;
    while (q.empty() == false) {
        pair<int,int> curr = q.front(); q.pop();
        int r = curr.first, c = curr.second;
        for (int i = 0; i < 4; i++) {
            int rc = r + dy[i], cc = c + dx[i];
            if (rc >= n || rc < 0 || cc >= n || cc < 0) {continue;}
            if (visited[rc][cc]) {continue;}
            // check for any roads:
            bool road = false;
            for (auto & [road_r, road_c] : adj[{r, c}]) {
                if (road_r == rc && road_c == cc) {road = true; break;}
            }
            if (road) {continue;}
            visited[rc][cc] = true;
            q.push({rc, cc});
        }
    }
}

int main() {
    cin >> n >> k >> r;
    visited.resize(n, vector<bool>(n,false));
    vector<pair<int,int>> cows;
    // store roads
    for (int i = 0; i < r; i++) {
        int r, c, rp, cp; cin >> r >> c >> rp >> cp;
        r--, c--, rp--, cp--;
        adj[{r, c}].push_back({rp, cp});
        adj[{rp, cp}].push_back({r, c});
    }
    // store cows
    for (int i = 0; i < k; i++) {
        int y, x; cin >> y >> x;
        y--, x--;
        cows.push_back(make_pair(y, x));
    }
    // search all pairs of cows possible
    int amt = 0;
    for (int i = 0; i < k; i++) {
        // bfs to see what cells it can visit without crossing roads
        bfs(cows[i]);

        // check for every cow, if the cell is visited as a result of doing bfs on cow i
        for (int j = i + 1; j < k; j++) {
            if (j == i ) continue;
            // if the other cows pos is NOT visited, the pair is distant
            if (!visited[cows[j].first][cows[j].second]) {amt++;}
        }
        visited.assign(n, vector<bool>(n, false));
    }
    
    cout << amt << endl;
}