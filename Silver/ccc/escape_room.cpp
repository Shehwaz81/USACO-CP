#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ld = long double;

int m, n; 
vector<vector<int>> grid;
vector<vector<bool>> visited;

map<int, vector<pair<int,int>>> val;

void dfs(pair<int, int> s) {
    int i = s.first, j = s.second;
    if (visited[i][j]) {return;}
    visited[i][j] = true;
    
    int x = grid[i][j];
    // search all possible nodes
    for (auto &[a, b] : val[x]) {
        if (!visited[a][b]) {dfs({a, b});}
    }

}

int main() {
    cin >> m >> n; // m rows, n columns
    
    grid.resize(m + 1, vector<int>(n + 1, 0)), visited.resize(m + 1, vector<bool>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            grid[i][j] = x;
            val[i * j].push_back({i, j}); // add to whatever product it would make, so later we can see all multiples of grid[i][j] that we can go to!
        }
    }
    // run dfs and then check visited[m][n] == true
    dfs({1, 1});
    
    if (visited[m][n]) {cout << "yes" << endl;}
    else {cout << "no" << endl;}
}