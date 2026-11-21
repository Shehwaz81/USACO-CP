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
using ll = long long;


int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n), freq(11, 0);
        for (auto& i : a) {cin >> i; freq[i]++;}

        for (int i = 10; i >= 0; i--) {
            if (freq[i] != 0) {
                cout << freq[i] << endl;
                break;
            }
        }
    }
}