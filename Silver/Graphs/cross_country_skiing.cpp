#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int,int>> points;
queue<pair<int,int>> q;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void bfs(pair<int, int> &s, int x) {
    q.push(s);
    while (q.empty() == false) {
        pair<int, int> curr = q.front(); q.pop();
        int l = curr.first; int r = curr.second;
        visited[l][r] = true;

        // find children that are valid
        for (int i = 0; i < 4; i++) {
            int lc = l + dx[i], rc = r + dy[i];
            if (lc >= n || lc < 0 || rc >= m || rc < 0) continue;
            if (abs(grid[l][r] - grid[lc][rc]) > x) continue;
            if (visited[lc][rc]) continue;
            visited[lc][rc] = true;
            q.push({lc, rc});
        }
    }
    
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m, -1)), visited.resize(n, vector<bool>(m, false));
    int max_e = 0;
    // first input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            max_e = max(max_e, grid[i][j]);
        }
    }
    // second input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val; cin >> val;
            if (val == 1) {points.push_back({i, j});} // push coords of waypoint
        }
        
    }
    // binary search
    int l = 0, h = max_e;
    while (l < h) {
        int mid = (l + h - 1) / 2;
        bfs(points[0], mid); // doesn't matter which point it is
        
        // check if this point is poss
        bool poss = true;
        for (auto &[i, j] : points) {
            if (!visited[i][j]) {poss = false; break;}
        }
        // binary conditions
        if (poss) {
            h = mid;
        } else {
            l = mid + 1;
        }
        visited.assign(n, vector<bool>(m, false));
    }
    
    cout << h << endl;
}
    