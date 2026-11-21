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
    set<pair<string,string>> x_set, y_set; // keep track of the distinct sets
    
    // MUST group
    int x; cin >> x;
    for (int i = 0; i < x; i++) {
        // include both to make it easier later
        string n1, n2; cin >> n1 >> n2;
        x_set.insert({n1, n2});
        x_set.insert({n2, n1});
    }
    
    // NOT group
    int y; cin >> y;
    for (int i = 0; i < y; i++) {
        string n1, n2; cin >> n1 >> n2;
        y_set.insert({n1, n2});
        y_set.insert({n2, n1});
    }
    
    int n; cin >> n;
    int y_violated = 0;
    for (int i = 0; i < n; i++) {
        string n1, n2, n3; cin >> n1 >> n2 >> n3;
        
        // first see if the students who are supposed to be together are together
        x_set.erase({n1, n2});
        x_set.erase({n2, n1});
        x_set.erase({n1, n3});
        x_set.erase({n3, n1});
        x_set.erase({n3, n2});
        x_set.erase({n2, n3});
        
        // now see if any people are NOT supposed to be together
        if (y_set.erase({n1, n2})) {
            y_violated++;
            y_set.erase({n2, n1});
        }
        if (y_set.erase({n2, n3})) {
            y_violated++;
            y_set.erase({n3, n2});
        }
        if (y_set.erase({n1, n3})) {
            y_violated++;
            y_set.erase({n3, n1});
        }
    }
    int x_violated = (x_set.size()) / 2;
    
    cout << x_violated + y_violated << endl;
}