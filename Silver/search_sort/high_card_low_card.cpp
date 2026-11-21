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
    vector<int> ef(n/2), es(n/2), bf, bs;
    map<int, int> freq; // keep track of what has been stored (#'s)
    
    for (int i = 0; i < (n / 2); i++) {
        cin >> ef[i];
        freq[ef[i]] = 1;
    }
    for (int i = 0; i < (n / 2); i++) {
        cin >> es[i];
        freq[es[i]] = 1;
    }
    sort(ef.begin(), ef.end());
    sort(es.rbegin(), es.rend());
    
    // find bessies numbers for high and low seperately
    int added = 0;
    for (int i = 1; i <= n * 2; i++) {
        if (freq.count(i) == 0) {bs.push_back(i); freq[i] = 1; added++;}
        if (added >= n / 2) {break;}
    }
    added = 0;
    for (int i = 1; i <= n * 2; i++) {
        if (freq.count(i) == 0) {bf.push_back(i); added++;}
        if (added >= n / 2) {break;}
    }
    
    // sort properly
    sort(bs.rbegin(), bs.rend());
    sort(bf.begin(), bf.end());
    
    // we use two pointer for first game
    int b_idx = 0, e_idx = 0, amt = 0;
    while (b_idx < n / 2 && e_idx < n / 2) {
        if (bf[b_idx] > ef[e_idx]) {
            amt++;
            b_idx++; e_idx++;
        } else {b_idx++;}
    }
    
    // same for 2nd game;
    b_idx = 0, e_idx = 0;
    while (b_idx < n / 2 && e_idx < n / 2) {
        if (bs[b_idx] < es[e_idx]) {
            amt++;
            b_idx++; e_idx++;
        } else {b_idx++;}
    }
    cout << amt << endl;
}