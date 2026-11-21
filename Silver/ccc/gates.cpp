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
    int g, p; cin >> g >> p;
    
    vector<bool> gate(g + 1, false);
    // just use a greedy algorithm. Place the current plane at the highest numbered gate 
    // possible for each plane.
    int ans = 0;
    for (int i = 0; i < p; i++) {
        int pi; cin >> pi;
        
        while (pi > 0 && gate[pi]) {pi--;}
        if (gate[pi] || pi == 0) {break;}
        
        gate[pi] = true;
        ans++;
    }
    cout << ans << endl;
}