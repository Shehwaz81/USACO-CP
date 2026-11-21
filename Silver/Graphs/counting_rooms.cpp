#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, m, comp_amt = 0;

void floodfill(int i, int j) { // we already know what are walls and floors
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (visited[i][j]) return;
    if (grid[i][j] == 1) return;
    visited[i][j] = true;
    
    floodfill(i + 1, j);
    floodfill(i, j + 1);
    floodfill(i - 1, j);
    floodfill(i, j - 1);

}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m, -1)), visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            grid[i][j] = (c == '#'); // floor = 0, wall = 1
        }
    }
    
    // run floodfill and calculate rooms
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 0) {
                floodfill(i, j);
                comp_amt++;
            }
        }
    }
    
    cout << comp_amt << endl;
    
}