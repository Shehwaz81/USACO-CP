#include <bits/stdc++.h>

using namespace std;
int n = 3;

int main() {
    int max_area = 0;
    vector<pair<int,int>> logo(n);
    for (int i = 0; i < n; i++) {
        cin >> logo[i].first >> logo[i].second;
        max_area += logo[i].first * logo[i].second;
    }
    int side = 1;
    while ((side * side) < max_area) {side++;}
    if (side * side != max_area) {
        cout << "-1" << endl;
        return 0;
    }
    
    for (int rotate = 0; rotate < (1 << n); rotate++) {
        vector<vector<char>> grid(side, vector<char>(side, '.'));
        int c = 0;
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                if (grid[i][j] != '.') continue;
                if (c >= 3) goto outer;
                int x = logo[c].first, y = logo[c].second;
                if (rotate & (1 << c)) swap(x, y);
                for (int row = i; row < i + y; row++) {
                    for (int col = j; col < j + x; col++) {
                        if (row >= side || col >= side) goto outer;
                        if (grid[row][col] != '.') goto outer;
                        grid[row][col] = 'A' + c;
                    }
                }
                c++;
            }
        }
        // By this point all logos have been placed in a sqaure shape
        cout << side << endl;
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) cout << grid[i][j];
            cout << endl;
        }
        return 0;
        outer:;
    }
    cout << "-1" << endl;
    return 0;
}