#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

vector<vector<ll>> grid, sum;
int n, k, q;

int main() {
    cin >> n >> k >> q;
    grid.resize(n, vector<ll>(n, 0)), sum.resize(n, vector<ll>(n, 0));
    vector<pair<int, int>> cows;
    ll max_beauty = 0;
    for (int i = 0; i < q; i++) {
        ll r, c, b;
        cin >> r >> c >> b;
        --r; --c;
        ll delta = b - grid[r][c] ;
        grid[r][c] = b;

        for (int j = r - k + 1; j <= r; j++) {
            for (int l = c - k + 1; l <= c; l++) {
                if (j >= 0 && l >= 0) {
                    sum[j][l] += delta;
                    max_beauty = max(max_beauty, sum[j][l]);
                }
            }
        }
        cout << max_beauty << endl;
    }
}