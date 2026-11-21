#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using p = pair<int,int>;


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<p> cows(n);
        map<int, vector<int>> l; // to store the amt of 
        set<int> next_pos; // keeps track of all actual Li positions that are actually inputted
        for (int i = 0; i < n; i++) {
            cin >> cows[i].first >> cows[i].second;
            l[cows[i].first].push_back(cows[i].second); // for index Li, push back Ri
            next_pos.insert(cows[i].first);
        }
        
        next_pos.insert(1e9 + 1); // insert a huge number so we can break out of while loop
        priority_queue<int, vector<int>, greater<int>> pq; // we want the least Ri first
        
        int i = *next_pos.begin();
        bool valid = true;
        while (i <= 1e9) {
            for (int r : l[i]) {pq.push(r);}
            int curr_r = pq.top(); pq.pop(); // we place curr at ith box pos
            if (curr_r < i) {valid = false; break;} // unessasary but who cares lol
            if (pq.empty()) {
                // skip to next position
                i = *next_pos.upper_bound(i);
            } else {
                if (pq.top() <= i) {valid = false; break;}
                else {i++;}
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
}
