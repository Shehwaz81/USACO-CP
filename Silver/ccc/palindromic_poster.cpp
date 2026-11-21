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

int main() {
    int n, m, r, c; cin >> n >> m >> r >> c;

    // initially, fill all cells with false (represents 'a), thus c == m and r == n
    vector<vector<char>> a(n, vector<char>(m, 'a'));
    int curr_c = m, curr_r = n;

    if (r == 0 && c == 0) {
        // destroy ALL palindroms (we don't change (1, 1))
        for (int i = 1; i < n; i++) {a[i][0] = 'b';}
        for (int i = 1; i < m; i++) {a[0][i] = 'b';}

    } else if (r == 0 && c > 0) {
        for (int i = 0; i < n; i++) {a[i][0] = 'b';}
        int idx = 0;
        while (curr_c > c && idx < m) {
            a[0][idx++] = 'c';
            curr_c--;
        }
    } else if (c == 0 && r > 0) {
        for (int i = 0; i < m; i++) {a[0][i] = 'b';}
        int idx = 0;
        while (curr_r > r && idx < n) {
            a[idx++][0] = 'c';
            curr_r--;
        }
    } else if (r == n && c < m) {
        // if it is even number of columns and c is odd, then that is impossible
        if (m % 2 == 0 && c % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        // if (m - c) is odd, then make the center of first row a 'b' initially
        if ((m - c) % 2 != 0 ) {
            a[0][((m + 1) / 2) - 1] = 'b';
            curr_c--; 
        }
        // two pointers to reduce curr_c
        int l = 0, ri = m - 1;
        while (l < ri && curr_c > c) {
            a[0][l++] = 'b', a[0][ri--] = 'b';
            curr_c -= 2;
        }
    } else if (c == m && r < n) {
        if (n % 2 == 0 && r % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        // if c is odd, then make the center of first row a 'b' initially
        if ((n - r) % 2 != 0) {
            a[((n + 1) / 2) - 1][0] = 'b';
            curr_r--;
        }
        // two pointers to reduce curr_c
        int l = 0, ri = n - 1;
        while (l < ri && curr_r > r) {
            a[l++][0] = 'b', a[ri--][0] = 'b';
            curr_r -= 2;
        }
    } else {
        int idx = 0;
        while (curr_c > c) {
            a[0][idx++] = 'b';
            curr_c--;
        }

        idx = 0;
        while (curr_r > r) {
            a[idx++][0] = 'b';
            curr_r--;
        }
    }

    //print final ans
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}