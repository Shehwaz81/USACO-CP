#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int total = 0;
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> p[i][j];
        }
        
        // calc contributions from every column
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            int rsum = 0, sum = 0;
            // calc total sum for this col and add to tmp vector
            for (int j = 0; j < n; j++) {
                sum += p[j][i];
                tmp.push_back(p[j][i]);
            }
            sort(all(tmp));
            // calc contrabutions
            for (int j = 0; j < n; j++) {
                rsum += tmp[j];
                total += abs(sum - rsum) - ((n - 1 - j) * tmp[j]);
            } 
            
        }
        cout << total << endl;
    }
}