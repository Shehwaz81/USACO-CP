#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int n; cin >> n;
    vector<pair<int,int>> cows(n);
    set<int> times;
    for (auto &[arrive, t] : cows) {
        cin >> arrive >> t;
    }
    sort(all(cows));
    int global_time = 0;
    while (cows.size() != 0) {
        if (global_time < cows[0].first) global_time = cows[0].first;
        global_time += cows[0].second;
        cows.erase(cows.begin());
    }
    cout << global_time << endl;
}