#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <cctype>
using namespace std;
using ll = long long;
using p = pair<int, int>;


int main() {
    int n, m, q; cin >> n >> m >> q;

    // also mantain a set of the top pretty values for each color
    vector<int> top1(m + 1, 0), top2(m + 1, 0);

    // get the top 1 and top 2 pretty pens for each color
    for (int i = 0; i < n; i++) {
        int c, p; cin >> c >> p;
        if (top1[c] == p) {top2[c] = p;}
        else if (top1[c] < p) {
            top2[c] = top1[c];
            top1[c] = p;
        } else {top2[c] = max(top2[c], p);}
    }

    // add all top 1 values to a multiset and then remove the lowest until size == n
    multiset<int> ms;
    for (int i = 1; i <= m; i++) {
        ms.insert(top1[i]);
    }
    
    ll sum = 0;
    for (auto e : ms) {sum += e;}

    int min_val = *ms.begin();
    int max_top2 = *max_element(top2.begin(), top2.end());
    int diff = max(0, max_top2 - min_val);

    cout << sum + diff << endl;
}