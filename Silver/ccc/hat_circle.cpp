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
    int n; cin >> n;
    
    vector<int> hat(n);
    for (int i = 0; i < n; i++) {
        cin >> hat[i];
    }

    // go through every person, if hat[i] is the same as hat[(i + (half of n)) % n], then add 1 to the ans
    int ans = 0, offset = n / 2;
    for (int i = 0; i < n; i++) {
        if (hat[i] == hat[(i + offset) % n]) {ans++;}
    }
    cout << ans << endl;
}