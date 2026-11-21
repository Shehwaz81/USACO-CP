#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

map<int, vector<int>> adj;
vector<int> power;
vector<pair<int, int>> pos;
vector<bool> visited;
int max_cows = 0, amt = 1;

void dfs(int s) {
    visited[s] = true;
    max_cows = max(max_cows, amt);
    for (int & child : adj[s]) {
        if (!visited[child]) {amt++; dfs(child);} // increase the amt (# of cows this one can reach) and dfs on the child
    }
    return;
}

int main() {
    int n; cin >> n;
    pos.resize(n), power.resize(n), visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second >> power[i];
    }
    // calculate edges
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (j == i) {continue;}
            int p = power[i]*power[i];
            int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            if (dist <= p) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    // now calculate largest component of the graph, as we don't need to do individual
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {dfs(i);}
        amt = 1;
    }
    cout << max_cows << endl;
}