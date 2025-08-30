#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int n; cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {char val = s[j]; grid[i][j] = (val == '1');}
    }
    // function to get subarray which you can tip over
    auto tip = [&](int y, int x) {
        int height = 0;
        while (y + height < n && grid[y + height][x]) height++;

        int width = n;
        for (int i = 0; i < height; i++) {
            int rowWidth = 0;
            while (x + rowWidth < n && grid[y + i][x + rowWidth]) rowWidth++;
            width = min(width, rowWidth);
        }
        // change everything on real grid
        for (int i = y; i < y + height; i++) {
            for (int j = x; j < x + width; j++) {grid[i][j] = 0;}
        }
    };
    // go through all cows, and then see how much you can top over without tipping already good cows
    int tips = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {tip(i, j); tips++;}
        }
    }
    cout << tips << endl;
}