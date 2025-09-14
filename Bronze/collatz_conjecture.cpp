#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> poss;

void check(int n, int x) {
    if (n == k) {
        poss.push_back(x);
        return;
    } else {
        if ((x - 1) % 3 == 0 && ((x - 1) / 3) % 2 != 0) {check(n + 1, (x - 1) / 3);}
        if ((x * 2) % 2 == 0) {check(n + 1, x * 2);}
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> k >> x;
        poss.resize(0);
        // simulate
        check(0, x);
        
        cout << poss[0] << endl;
    }
}