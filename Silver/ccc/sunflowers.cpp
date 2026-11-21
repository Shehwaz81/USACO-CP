#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using d = double;

int n;

// rotate clockwise
void rotate(vector<vector<int>>& g) {
    vector<vector<int>> ng(n + 1, vector<int>(n + 1, 0)); // new grid
    
    // formula to rotate an array 90 deg
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            ng[x][n - y + 1] = g[y][x];
        }
    }

    g = ng;
}

bool check(vector<vector<int>>& g) {
    // if corner 1 is the minimum corner, then the orientation is correct
    if (g[1][1] < g[1][n] && g[1][1] < g[n][1] && g[1][1] < g[n][n]) {return true;}
    return false;
}

int main() {
    cin >> n;
    
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {cin >> grid[i][j];}
    }
    
    // rotate until valid (with cnt gaurdrail)
    int cnt = 0;
    while (!check(grid) && cnt < 5) {
        rotate(grid); cnt++;
    }
    
    // print grid
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}