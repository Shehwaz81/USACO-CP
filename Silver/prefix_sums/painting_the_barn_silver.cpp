#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define all(x) (x).begin(), (x).end()

const int Y = 1000, X = 1000;
vector<vector<int>> diff(Y + 1, vector<int>(X + 1));

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        // store all values in 2d difference array
        diff[y1][x1]++, diff[y2][x2]++;
        diff[y1][x2]--, diff[y2][x1]--;
    }
    // compute difference array into pref array and then see if each cell is equal to k
    int ans = 0;
    for (int y = 0; y <= Y; y++) {
        for (int x = 0; x <= X; x++) {
            if (x > 0) diff[x][y] += diff[x - 1][y];
            if (y > 0) diff[x][y] += diff[x][y - 1];
            if (x > 0 && y > 0) {diff[x][y] -= diff[x - 1][y - 1];}
            if (diff[x][y] == k) ans++;
        }
    }
    cout << ans << endl;
}