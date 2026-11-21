#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;
int n;

void dfs(int sx, int ex, int sy, int ey, pair<int,int> curr, char color) {
    int curr_y = curr.first, curr_x = curr.second;
    // check for out of bounds
    if (curr_y < sy || curr_y > ey || curr_x < sx || curr_x > ex) {return;}
    // check if amt of colors is over 2
    if (grid[curr_y][curr_x] != color) {return;}
    // visited check
    if (visited[curr_y][curr_x]) {return;}
    
    visited[curr_y][curr_x] = true;
    
    // search all adjecent cells
    dfs(sx, ex, sy, ey, {curr_y + 1, curr_x}, color);
    dfs(sx, ex, sy, ey, {curr_y - 1, curr_x}, color);
    dfs(sx, ex, sy, ey, {curr_y, curr_x + 1}, color);
    dfs(sx, ex, sy, ey, {curr_y, curr_x - 1}, color);
}


bool check(int sx, int ex, int sy, int ey) {
    // bfs
    // scan for components
    map<char, int> freq;
    bool impossible = false;
    set<char> colors;
    for (int k = sy; k <= ey; k++) {
        for (int l = sx; l <= ex; l++) {
            if (!visited[k][l]) {
                dfs(sx, ex, sy, ey, {k, l}, grid[k][l]);
                colors.insert(grid[k][l]);
                freq[grid[k][l]]++;
            }
            if (colors.size() > 2) {
                impossible = true; break;
            }
        }
        if (impossible) {break;}
    }
    // check if poss
    int one = 0, multiple = 0;
    for (auto &[color, amt] : freq) {
        if (amt == 1) {one++;}
        else if (amt > 1) {multiple++;}
    }
    
    if (!impossible && colors.size() == 2 && one == 1 && multiple == 1) {
        return true;
    }
    return false;
}

bool is_true(vector<int> &r1, vector<int> &r2) {
    if (r1[0] >= r2[0] && r1[1] <= r2[1] && r1[2] >= r2[2] && r1[3] <= r2[3]) {
        return false;
    } else {return true;}
}


int main() {
    cin >> n;
    grid.resize(n, vector<char>(n)), visited.resize(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {cin >> grid[i][j];}
    }
    
    // complete search
    vector<vector<int>> poss;
    for (int i = 0; i < n; i++) { // y beginning
        for (int y = i; y < n; y++) { // y end
            for (int j = 0; j < n; j++) { // x beginning
                for (int x = j; x < n; x++) { // x end
                    if (check(j, x, i, y)) {
                        // push back rectangle so we can check if it is a distinct one
                        poss.push_back({j, x, i, y});
                    }
                    visited.assign(n, vector<bool>(n, false));
                }
            }
        }
    }
    // calc points
    int amt = 0;
    for (int i = 0; i < poss.size(); i++) {
        bool istrue = true;
        for (int j = 0; j < poss.size(); j++) {
            if (j == i) continue;
            if (!is_true(poss[i], poss[j])) {istrue = false; break;}
        }
        if (istrue) amt++;
    }
    
    cout << amt << endl;
}
