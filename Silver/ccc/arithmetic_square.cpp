#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 5;

int full_rows = 0, full_columns = 0, values = 0;

vector<vector<int>> g(3, vector<int>(3, INF));
vector<int> r_amt(3, 0), c_amt(3, 0);
vector<set<pii>> r(3), c(3);


// if two values are present, fill the 3rd value
void fillR(int i) {
    int v1 = r[i].begin()->second, v2 = (++r[i].begin())->second;
    int p1 = r[i].begin()->first, p2 = (++r[i].begin())->first;
    
    int d = (v2 - v1) / (p2 - p1);

    if (g[i][0] == INF) {
        g[i][0] = g[i][1] - d;
        c_amt[0]++;
        c[0].insert({i, g[i][0]});
    }
    if (g[i][1] == INF) {
        g[i][1] = g[i][2] - d;
        c_amt[1]++;
        c[1].insert({i, g[i][1]});
    }
    if (g[i][2] == INF) {
        g[i][2] = g[i][1] + d;
        c_amt[2]++;
        c[2].insert({i, g[i][2]});
    }

    r_amt[i]++;
    full_rows++;
}

void fillC(int i) {
    int v1 = c[i].begin()->second, v2 = (++c[i].begin())->second;
    int p1 = c[i].begin()->first, p2 = (++c[i].begin())->first;
    
    int d = (v2 - v1) / (p2 - p1);

    if (g[0][i] == INF) {
        g[0][i] = g[1][i] - d;
        r_amt[0]++;
        r[0].insert({i, g[0][i]});
    }
    if (g[1][i] == INF) {
        g[1][i] = g[2][i] - d;
        r_amt[1]++;
        r[1].insert({i, g[1][i]});
    }
    if (g[2][i] == INF) {
        g[2][i] = g[1][i] + d;
        r_amt[2]++;
        r[2].insert({i, g[2][i]});
    }

    c_amt[i]++;
    full_columns++;
}

int check() {
    int changes = 0;

    // check rows
    for (int i = 0; i < 3; i++) {
        if (r_amt[i] == 2) {
            changes++, values++;
            fillR(i);
        }
    }
    // now see columns
    for (int i = 0; i < 3; i++) {
        if (c_amt[i] == 2) {
            changes++, values++;
            fillC(i);
        }
    }
    return changes;
}

int main() {

    // populate grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string x; cin >> x;
            if (x != "X") {
                values++;
                g[i][j] = stoi(x);

                r_amt[i]++, c_amt[j]++;
                if (c_amt[i] == 3) {full_columns++;}
                if (r_amt[i] == 3) {full_rows++;}

                r[i].insert({j, stoi(x)}), c[j].insert({i, stoi(x)});
            }
        }
    }

    // if only 1 or 2 values were given:
    if (values == 1 || values == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {cout << 1 << ' ';}
            cout << endl;
        }
        return 0;
    }


    // first fill in all cells that NEED to be filled it (all columns and rows that have 2)
    while (true) {
        // check if any rows/columns are filled with 2,if they are, call fillC or fillR
        int changes = check();

        if (changes == 0) {break;}
    }

    // now, there are only a few possible cases

    if (full_rows == 1 && full_columns == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {g[i][j] = c[j].begin()->second;} // set it to the only value in that column
        }

    } else if (full_rows == 1 && full_columns == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {g[j][i] = r[j].begin()->second;} // set it to the only value in that row
        }
    } else {
        while (values != 9) {

            // pick one spot to be filled
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (g[i][j] != INF) continue;

                    if (r_amt[i] == 1 && c_amt[j] == 1) {
                        int val_r = r[i].begin()->second, pos_r = r[i].begin()->first;
                        int val_c = c[j].begin()->second, pos_c = c[j].begin()->first;

                        int num = 1;
                        if (abs(val_r - num) % abs(pos_r - j) != 0) {num++;}
                        else if (abs(val_c - num) % abs(pos_c - i) != 0) {num++;}
                        g[i][j] = num;

                        c_amt[j]++, r_amt[i]++;
                        c[j].insert({i, num}), r[i].insert({j, num});
                        values++;
                    }
                    goto found;
                }
            }

            found:
            // fill in all rows/cols with 2
            while (true) {
                int changes = check();

                if (changes == 0) {break;}
            }
        }
    }

    // print grid;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}