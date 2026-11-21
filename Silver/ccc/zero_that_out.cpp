#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;


int main() {
    int k; cin >> k;
    vector<int> q;
    for (int i = 0; i < k; i++) {
        int v; cin >> v;
        if (v == 0 && q.size() > 0) {q.pop_back();}
        else {q.push_back(v);}
    }
    
    int sum = 0, s = q.size();
    for (int i = 0; i < s; i++) {sum += q[i];}
    
    cout << sum << endl;
}