#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct f {
    ll p, w, d;
};

int n;
vector<f> person;


int main() {
    cin >> n;

    person.resize(n);

    using pll = pair<ll, ll>;
    priority_queue<pll, vector<pll>, greater<pll>> min_pq;
    priority_queue<pll> max_pq;
    set<ll> pref_pos;
    set<ll, greater<ll>>  suff_pos;

    // get input and populate priority queues
    for (int i = 0; i < n; i++) {
        cin >> person[i].p >> person[i].w >> person[i].d;

        min_pq.push({person[i].p + person[i].d, person[i].w});
        max_pq.push({person[i].p - person[i].d, person[i].w});

        pref_pos.insert(person[i].p);
        pref_pos.insert(person[i].p + person[i].d);
        pref_pos.insert(person[i].p - person[i].d);

        suff_pos.insert(person[i].p);
        suff_pos.insert(person[i].p + person[i].d);
        suff_pos.insert(person[i].p - person[i].d);
    }

    // make prefix array
    map<ll, ll> pref;
    ll tot_multiplier = 0, last_p = *pref_pos.begin();
    pref[last_p] = 0;
    for (ll p : pref_pos) {
        if (p == last_p) {continue;}

        // add contribution
        pref[p] += pref[last_p] + (p - last_p) * tot_multiplier;

        // first see if there are any friends in pq that can be released
        while (min_pq.empty() == false && min_pq.top().first <= p) {
            tot_multiplier += min_pq.top().second;
            pref[p] += (p - min_pq.top().first) * min_pq.top().second; // add if there is distance to be covered 
            min_pq.pop();
        }

        last_p = p;
    }


    // make suffix sum array
    map<ll, ll> suff;
    tot_multiplier = 0, last_p = *suff_pos.begin();
    suff[last_p] = 0;
    for (ll p : suff_pos) {
        if (p == last_p) {continue;}

        // add contribution
        suff[p] += suff[last_p] + (abs(p - last_p) * tot_multiplier);

        // first see if there are any friends in pq that can be released
        while (max_pq.empty() == false && max_pq.top().first >= p) {
            tot_multiplier += max_pq.top().second;
            suff[p] += abs(p - max_pq.top().first) * max_pq.top().second; // add if there is distance to be covered 
            max_pq.pop();
        }

        last_p = p;
    }
    
    // now, see what is the optimal
    ll ans = LLONG_MAX;
    for (ll p : pref_pos) {
        ll tot = suff[p] + pref[p];
        ans = min(tot, ans);
    }

    cout << ans << endl;
}