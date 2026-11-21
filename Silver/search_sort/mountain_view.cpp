#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define all(x) (x).begin, (x).end()
using ll = long long;

struct M {
    ll x, y;
    // sort by decreasing cash or increasing gallons
    bool operator<(const M& m) const {
        if (x != m.x) {return x < m.x;}
        return y > m.y;
    }
};
vector<bool> visable;

ll calc(ll x, ll y, ll curr_x) {
    return (y + (curr_x - x)); // the current y value
}

ll xInt(ll x, ll y) {
    ll c = x + y;
    return (c * 2);
}

int main() {
    int n; cin >> n;
    visable.resize(n, true);
    vector<M> mount(n);
    for (int i = 0; i < n; i++) {
        cin >> mount[i].x >> mount[i].y;
    }
    sort(mount.begin(), mount.end());
    
    // go through each and keep track of the max_right
    ll max_right = 0;
    for (int i = 0; i < n; i++) {
        ll y = calc(mount[i].x, mount[i].y, mount[i].x);
        if (y <= max_right) {visable[i] = false;}
        max_right = max(max_right, y);
        for (int j = 0; j < i; j++) {
            if (!visable[j]) {continue;}
            ll curr_y = calc(mount[i].x, mount[i].y, mount[j].x);
            if (curr_y >= mount[j].y) {visable[j] = false;}
        }
    }
    int amt = 0;
    for (auto b : visable) {
        if (b) {amt++;}
    }
    cout << amt << endl;
}