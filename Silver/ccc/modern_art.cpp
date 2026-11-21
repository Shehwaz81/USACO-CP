#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ld = long double;

vector<int> a, b;

int main() {
    int m, n, k; cin >> n >> m >> k;

    vector<bool> rows(n + 1, false), cols(m + 1, false); // set all rows and columns to 0 (black) initially

    int rg = 0, cg = 0; // # of rows and columns that are gold
    int amt = 0;
    while (k--) {
        char c; cin >> c;
        int i; cin >> i;

        if (c == 'R') {
            // if rows[i] is NOT gold already
            if (!rows[i]) {
                amt += m - (2 * cg);
                rg++;
                rows[i] = true; // set to gold
            } else {
                amt += (2 * cg) - m;
                rg--;
                rows[i] = false; // set to black
            }
        } else {
            // if cols[i] is NOT gold already
            if (!cols[i]) {
                amt += n - (2 * rg);
                cg++;
                cols[i] = true; // set to gold
            } else {
                amt += (2 * rg) - n;
                cg--;
                cols[i] = false; // set to black
            }
        }
    }

    cout << amt << endl;
}