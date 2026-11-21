#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct Cow {
    int a, dur, s;
    bool operator<(const Cow c) const {
        return a < c.a;
    }
};

int main() {
    int n; cin >> n;
    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].a >> cows[i].dur;
        cows[i].s = i + 1; // senority
    }
    sort(cows.begin(), cows.end());
    
    // make the pq sort by seniority
    auto sortSenority = [](const Cow c1, const Cow c2) {
        return c1.s > c2.s;
    };
    priority_queue<Cow, vector<Cow>, decltype(sortSenority)> pq(sortSenority);
    
    // start a while loop
    int idx = 0, curr_time = 0, max_wait = 0;
    while (idx < n) {
        // get current cow
        Cow curr_cow;
        if (pq.size() == 0) {
            curr_cow = cows[idx];
            idx++;
        } else {
            curr_cow = pq.top(); pq.pop();
        }
        // update max wait time and curr time
        max_wait = max(max_wait, curr_time - curr_cow.a);
        curr_time = max(curr_time, curr_cow.a);
        curr_time += curr_cow.dur;
        
        // add cows that would be waiting while curr_cow finishes
        while (idx < n && cows[idx].a <= curr_time) {
            if (cows[idx].a <= curr_time) {
                pq.push(cows[idx]); 
                idx++;
            } else {break;}
        }
    }
    cout << max_wait << endl;
}