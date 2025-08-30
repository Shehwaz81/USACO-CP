#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

vector<vector<int>> grid;
vector<vector<bool>> checked;
int n;

int main() {
    cin >> n;
    grid.resize(n, vector<int>(n)), checked.resize(n, vector<bool>(n, false));
    // load all beauty values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {cin >> grid[i][j];}
    }
    
    // find the max value of alternating between cow and no cow in each col
    int altColAmt = 0;
    for (int col = 0; col < n; col++) {
        // a new technique the editorial used, sum[2]{} which initializes all elements to 0
        int sum[2]{};
        for (int row = 0; row < n; row++) {sum[row % 2] += grid[row][col];}
        altColAmt += max(sum[1], sum[0]);
    }
    // find the max if we are alternating every row
    int altRowAmt = 0;
    for (int row = 0; row < n; row++) {
        int sum[2]{};
        for (int col = 0; col < n; col++) {sum[col % 2] += grid[row][col];}
        altRowAmt += max(sum[0], sum[1]);
    }
    int b = max({altRowAmt, altColAmt});
    cout << b << endl;
} 