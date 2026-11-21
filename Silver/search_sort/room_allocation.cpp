#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;


struct cust {
    int id, a, d;
    
    // sort by arrival ascending
    bool operator<(const cust c) const {
        return a < c.a;
    }
};


int main() {
    int n; cin >> n;
    
    using room = pair<int , int>;
    priority_queue<room, vector<room>, greater<room>> pq; // store end date and room #
    vector<cust> p(n);
    
    // take in input and sort, also store original place
    for (int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].d;
        p[i].id = i;
    }
    sort(p.begin(), p.end());

    int room_amt = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (pq.size() == 0 || p[i].a <= pq.top().first) {
            room_amt++;
            pq.push({p[i].d, room_amt});
            ans[p[i].id] = room_amt;
        } else {
            room ready = pq.top(); pq.pop();
            pq.push({p[i].d, ready.second});
            ans[p[i].id] = ready.second;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}