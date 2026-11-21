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
    int n, k; cin >> n >> k;

    // create array with all o initially
    vector<char> a(n, 'O');

    vector<vector<int>> d(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> d[i][0] >> d[i][1] >> d[i][2];
    }

    // complete search by adding an m for each iteration, and then generating all possible permutations
    int best = 0;
    unordered_map<int, int> freq;
    int m_amt = (n / 3) + (n % 3 == 0);
    for (int i = 0; i < m_amt; i++) {
        a[i] = 'M';
        vector<char> ac = a;
        do {
            int cnt = 0;
            for (auto m : d) {
                if (ac[m[0] - 1] == 'M' && ac[m[1] - 1] == 'O' && ac[m[2] - 1] == 'O') {cnt++;}
            }
            freq[cnt]++;
            best = max(best, cnt);
        } while (next_permutation(ac.begin(), ac.end()));
    }
    
    cout << best << ' ' << freq[best] << endl;
}