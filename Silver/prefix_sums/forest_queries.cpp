#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> grid(n + 1, (vector<int>(n + 1, 0)));
    // make 2d pref sum so we can compute in o(1) time per rectangle!
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            grid[i][j] += (c == '*' ? 1 : 0);
            grid[i][j] += (grid[i - 1][j] + grid[i][j - 1]) - grid[i - 1][j - 1];
        }
    }
    // compute all rectangles
    while (q--) {
        int x1, x2, y1, y2; cin >> y1 >> x1 >> y2 >> x2;
        int trees = grid[y2][x2] - grid[y1 - 1][x2] - grid[y2][x1 - 1] + grid[y1 - 1][x1 - 1];
        cout << trees << "\n";
    }
    
}