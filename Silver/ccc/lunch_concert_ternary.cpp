#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct f {
    ll p, w, d;
};

int n;
vector<f> person;

ll calc(ll x) {
    ll dist = 0;
    for (auto &[p, w, d] : person) {
        // if person is already within hearing dist, continue
        if (x <= p + d && x >= p - d) {continue;}

        // calculate min distance needed (weither that be from + d or - d)
        ll dist_needed = min(abs(p + d - x), abs(p - d - x));

        dist += dist_needed * w;
    }

    return dist;
}


int main() {
    cin >> n;

    person.resize(n);

    // get input and min/max pos for ternary search 
    ll min_pos = LLONG_MAX, max_pos = 0;
    for (int i = 0; i < n; i++) {
        cin >> person[i].p >> person[i].w >> person[i].d;
        min_pos = min(min_pos, person[i].p);
        max_pos = max(max_pos, person[i].p);
    }

    // ternary search
    ll l = min_pos, h = max_pos;
    while (h - l > 2) {
        ll m1 = l + (h - l) / 3;
        ll m2 = h - (h - l) / 3;

        if (calc(m1) <= calc(m2)) {
            h = m2; // minimum is in [l, m2] (function is increasing towards the right, or CANNOT be toward the right)
        } else {
            l = m1; // minimum is in [m1, h] (function is increasing towards the left, or CANNOT be toward the left)
        }
    }


    cout << min({calc(l), calc(l + 1), calc(h)}) << endl;

}