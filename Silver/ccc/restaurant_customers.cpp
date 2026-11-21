#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;


int main() {
    int n; cin >> n;
    
    vector<pair<int,int>> p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int curr_amt = 0, best = 0;
    
    for (auto &[a, d] : p) {
        // delete all people who are supposed to be gone atp
        while (!pq.empty() && pq.top() < a) {
            pq.pop(); 
            curr_amt--;
        }
        pq.push(d);
        curr_amt++;
        
        best = max(curr_amt, best);
    }
    
    cout << best << endl;
}