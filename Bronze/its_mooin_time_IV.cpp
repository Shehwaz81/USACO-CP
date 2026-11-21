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
    int t, k; cin >> t >> k;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (k == 0) {cout << "YES" << endl; continue;}

        vector<char> a(n);
        bool change = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'O') {
                if (!change) {
                    change = !change;
                    a[i] = 'O';
                } else {a[i] = 'M';}
            } if (s[i] == 'M') {
                if (change) {
                    change = !change;
                    a[i] = 'O';
                } else {a[i] = 'M';}
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {cout << a[i];}
        cout << endl;
    }
}