#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct event {
    int start, end, type, can_cut;
    
    bool operator<(const event& e) const {
        if (start != e.start) {return start < e.start;}
        return type < e.type; // puts -1 before 0 (restriction before tree);
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        
        vector<event> e;
        vector<int> cows(n);
        // trees
        for (int i = 0; i < n; i++) {
            cin >> cows[i];
            e.push_back({cows[i], 0, 0, 0});
        }
        sort(cows.begin(), cows.end());
        
        // restrictions
        for (int i = 0; i < k; i++){
            int l, r, res; cin >> l >> r >> res;
            // find how many trees total
            int tot_trees =  upper_bound(cows.begin(), cows.end(), r) - lower_bound(cows.begin(), cows.end(), l);
            // add to events vector
            e.push_back({l, r, -1, tot_trees - res});
        }

        sort(e.begin(), e.end());
        
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        int amt_cut = 0;
        for (auto &[start, end, type, can_cut] : e) {
            if (type == -1) {
                // we want to sort by min possible amt_cut + can_cut,
                // but we also need the end point of the restriction
                pq.push({amt_cut + can_cut, end});
            } else {
                // remove any restrictions that DONT apply anymore
                while (pq.empty() == false && pq.top().second < start) {pq.pop();}
                if (pq.empty() || pq.top().first > amt_cut) {
                    // cut the current tree down as we can without violating restrictions
                    amt_cut++;
                } else {
                    // we ignore as this means that amt_cut == what we can cut based on
                    // restriction(s)
                    continue;
                }
            }
        }
        cout << amt_cut << endl;
    }
}