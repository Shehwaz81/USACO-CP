#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    vector<vector<bool>> grid(2001, vector<bool>(2001, 0));
    auto convert = [](int x) {return x + 1000;};
    for (int i = 0; i < 3; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int y = convert(y1); y < convert(y2); y++) {
            for (int x = convert(x1); x < convert(x2); x++) {
                if (i != 2) grid[y][x] = true;
                else grid[y][x] = false;
            }
        }
    }
    int area = 0;
    for (auto & row : grid) {
        for (bool c : row) area += c;
    }
    cout << area << endl;
}