#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end();
using namespace std;

map<int, int> counter;

int main() {
    int n; cin >> n;
    int e = n - 1;
    vector<vector<int>> factory(n, vector<int>());

    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        factory[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++) {
        vector<bool> checked(n, false);
        vector<int> curr_stack = {i};
        while (true) {
            vector<int> stack;
            for (int & curr : curr_stack) {
                for (int & n : factory[curr]) {
                    if (!checked[n]) {checked[n] = true; stack.push_back(n);}
                }
            }
            if (stack.size() == 0) {break;}
            curr_stack = stack;
        }
        for (int i = 0; i < n; i++) {counter[i]+= checked[i];}
    }
    bool valid = false;
    for (auto &[f, amt] : counter) {
        if (amt == e) {cout << f + 1 << endl; valid = true; break;}
    }
    if (!valid) cout << -1 << endl;
}