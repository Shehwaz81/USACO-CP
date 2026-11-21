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
    int j, a; cin >> j >> a;
    map<char, set<int>> jersey;
    
    for (int i = 1; i <= j; i++) {
        char s; cin >> s;
        jersey[s].insert(i);
    }

    int ans = 0;
    for (int i = 0; i < a; i++) {
        char s; cin >> s;
        int id; cin >> id;
        if (s == 'S' && jersey['S'].find(id) != jersey['S'].end()) {
            ans++; 
            jersey['S'].erase(id);
        }
        else if ((s == 'M' || s == 'S') && jersey['M'].find(id) != jersey['M'].end()) {
            ans++; 
            jersey['M'].erase(id);
        }
        else if (jersey['L'].find(id) != jersey['L'].end()) {
            ans++; 
            jersey['L'].erase(id);
        }
    }
    
    cout << ans << endl;
}