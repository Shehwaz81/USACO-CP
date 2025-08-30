#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end();
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> judge(n + 1, 0), score(k);
    for (int i = 1; i < n + 1; i++) {
        int val; cin >> val;
        judge[i] = val + judge[i - 1]; // add up the total score that would be given/subtracted after each judge scores
    }
    for (int &s : score) cin >> s;
    // calc all possible starting positions of the contestant
    set<int> poss;
    for (int i = 1; i < n + 1; i++) {poss.insert(score.front() - judge[i]);} // we can do this with any of polycarp's scores, because its basically the score - prefix[i], and it doesn't matter what score we use as the question said that the scores are in no particular order. So if we were to assume 1 is the right one that would be wrong, instead we check one, at each position possible, subtracting the prefix of that position
    // go through every possible, checking if its a valid possible;
    int possAmt = 0;
    for (auto p : poss) {
        set<int> all_points;
        bool valid = true;
        for (int i = 1; i < n + 1; i++) {all_points.insert(p + judge[i]);} // calc all possible points with that starting amt;
        // check if all the points match up with the scores polycarp gives
        for (int & s : score) {
            if (all_points.find(s) == all_points.end()) {valid = false; break;}
        }
        if (valid) {possAmt++;}
    } 
    cout << possAmt << endl;
}