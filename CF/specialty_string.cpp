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

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        // do until you cannot change anything anymore
        while (true) {
            bool change = false;

            for (int i = 0; i < n - 1; i++) {
                if (s[i] == s[i + 1]) {
                    change = true;
                    s.erase(i + 1, 1);
                    s.erase(i, 1);
                    n -= 2;
                    break; // as we have changed the size of the string
                }
            }

            if (!change) {break;}
        }

        if (s.size() != 0) {cout << "NO" << endl;}
        else {cout << "YES" << endl;}
    }
}