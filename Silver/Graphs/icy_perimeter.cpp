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
vector<pair<int, int>> comp;
int n, curr_area = 0, curr_p = 0;

void floodfill(int i, int j) {
    if (i >= n || j >= n || j < 0 || i < 0) {
        curr_p++;
        return;
    }
    if (grid[i][j] != 0) {
        curr_p++;
        return;
    }
    if (visited[i][j]) return;
    
    visited[i][j] = true;
    curr_area++;
    
    floodfill(i + 1, j);
    floodfill(i, j + 1);
    floodfill(i - 1, j);
    floodfill(i, j - 1);

}

int main() {
    cin >> n;
    grid.resize(n, vector<int>(n, -1)), visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i][j] = (c == '.'); // icecream = 0, none = 1
        }
    }
    // floodfill and max area
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                floodfill(i, j);
                comp.push_back({curr_area, curr_p});
                max_area = max(max_area, curr_area);
                curr_area = 0;
                curr_p = 0;
            }
        }
    }
    // find ans
    int max_p = 0;
    pair<int,int> ans;
    for (auto &[a, p] : comp) {
        if (a == max_area && p > max_p) {ans = {a, p};} 
    }
    cout << ans.first << ' ' << ans.second << endl;
}