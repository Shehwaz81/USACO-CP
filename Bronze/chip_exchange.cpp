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

int main() {
    ll t; cin >> t;
    while (t--) {
        int A, B, cA, cB, fA; cin >> A >> B >> cA >> cB >> fA;
        
        // solve:
        ll initial_A = A + (B / cB) * cA;
        if (initial_A >= fA) {cout << 0 << endl; continue;}
        
        ll max_A = fA - 1 - initial_A; // how much A chips we can add BEFORE it reaches fA
        
        ll y = cB - 1 - (B % cB); // 1 before how much chips are needed for another exchange
        if (cB >= cA) {
            y += (max_A / cA) * cB;
        } else if (cA >= cB) {
            y += max_A;
        }
        
        cout << y + 1 << endl;
    }
}