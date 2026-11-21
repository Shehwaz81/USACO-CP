#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

struct op {
    int type, x, y, p; // for type 1 only, but we can use for type 2 as well
};

int main() {
    int T; cin >> T;

    while (T--) {
        int n, m; cin >> n >> m;
        string t; cin >> t;

        vector<string> s(n);
        for (int i = 0; i < n; i++) {cin >> s[i];}

        vector<op> ops; // keep track of all the operations we will do

        for (int i = 0; i < m; i++) {
            if (s[0][i] == t[i]) {continue;}

            // search all other strings to see where the required char is
            int x = -1e9, c = -1e9;
            for (int j = 0; j < n; j++) {
                int k_start = (j == 0 ? i + 1 : 0); // if the current string is the 1st, then we cannot search any index before i, as we have already built those
                for (int k = k_start; k < m; k++) {
                    if (s[j][k] == t[i]) {x = j; c = k; goto found;}
                }
            }

            found:
            // now, see all cases
            if (x == 0) { // operation type 1
                ops.push_back({1, 1, i + 1, c + 1});
                swap(s[0][i], s[0][c]);
            } 
            else { /// operation type 2

                // if the chars are not in the same index of the different strings, then we must first move them to the same index
                if (i != c) {
                    ops.push_back({1, x + 1, i + 1, c + 1});
                    swap(s[x][i], s[x][c]);
                }

                // now, we can do the swap required
                ops.push_back({2, 1, x + 1, i + 1}); // in this case, k == i
                swap(s[0][i], s[x][i]);
            }
        }

        cout << ops.size() << endl;

        for (auto [type, x, y, z] : ops) {
            cout << type << ' ' << x << ' ' << y << ' ' << z << endl;
        }
    }
}