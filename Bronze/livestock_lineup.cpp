#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella",  "Blue", "Betsy", "Sue"};
const int S = 8;

int main() {
    sort(all(cows));
    map<string, int> cowIndex; // map cow names to cow index
    vector<vector<int>> cowAdj(S, vector<int>()); // adj list for all cows, cows with no neighbors are considered len = 1
    int n; cin >> n;

    for (int i = 0; i < S; i++) {cowIndex[cows[i]] = i;}

    for (int i = 0; i < n; i++) {
        string cow1, cow2, na;
        cin >> cow1 >> na >> na >> na >> na >> cow2;
        int ind1 = cowIndex[cow1], ind2 = cowIndex[cow2];
        cowAdj[ind1].push_back(ind2);
        cowAdj[ind2].push_back(ind1);
    }
    vector<int> order, ordered(S, 0);
    // now, in go through all cows in lexographical order, if and ONLY IF a cow is the start of the chain, do we want to add it to the order
    for (int i = 0; i < S; i++) {
        if (!ordered[i] && cowAdj[i].size() == 0) {order.push_back(i); ordered[i] = true;} // if the cow is len 1, we dont need to traverse through its' neighbors, so we just add
        else if (!ordered[i] && cowAdj[i].size() == 1) {
            order.push_back(i);
            ordered[i] = true;
            int curr = cowAdj[i][0], prev = i;
            while (cowAdj[curr].size() == 2) {
                order.push_back(curr);
                ordered[curr] = true;
                int nextCow = cowAdj[curr][0] == prev ? cowAdj[curr][1] : cowAdj[curr][0]; // get the next cow in the traversal, make sure it isn't the same cow that we added in the past (prev)
                prev = curr;
                curr = nextCow;
            }
            // now we know we are on the last cow in the traversal, so add it and move on
            order.push_back(curr);
            ordered[curr] = true;
        }
    }
    for (int & cow : order) {cout << cows[cow] << endl;}
}