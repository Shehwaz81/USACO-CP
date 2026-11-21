#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> curr_type;
bool impossible = false;

void dfs(int s) {
    visited[s] = true;
    if (curr_type[s] == -1) {curr_type[s] = 0;} // set 0 as default
    for (auto & [child, type] : adj[s]) {
        // if the child node has already been assigned a plant type
        if (curr_type[child] != -1) {
            if (type == 1 && curr_type[child] == curr_type[s]) {impossible = true;}
            if (type == 0 && curr_type[child] != curr_type[s]) {impossible = true;}
            else {continue;}
        }
        if (type == 0) curr_type[child] = curr_type[s];
        else if (type == 1) {curr_type[child] = (curr_type[s] == 0 ? 1 : 0);} // switch
        
        dfs(child);
    }
}

int main() {
    cin >> n >> m;
    visited.resize(n + 1, false), curr_type.resize(n + 1, -1), adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        int p1, p2; cin >> p1 >> p2;
        adj[p1].push_back({p2, (c != 'S')});
        adj[p2].push_back({p1, (c != 'S')});
    }
    
    // calculate how much connected componentes are valid, 
    // if even 1 is invalid, the output should be 0 as the coniditons cannot be fulfilled
    int comp_amt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {continue;}
        dfs(i);
        
        // if it is deemed impossible, there are no ways to arrange the types
        if (impossible) {cout << 0 << endl; return 0;}
        // else, add the the component amount
        comp_amt++;
    }
    // output # in binary
    cout << 1;
    for (int i = 0; i < comp_amt; i++) {cout << 0;}
    cout << '\n';
}