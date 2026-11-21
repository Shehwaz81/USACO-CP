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
    int n, m, k; cin >> n >> m >> k;
    vector<int> rooms(m), p(n);
    
    for (auto &i : p) {cin >> i;}
    for (auto &i : rooms) {cin >> i;}
    
    sort(rooms.begin(), rooms.end());
    sort(p.begin(), p.end());

    // two pointers
    int applicant_pointer = 0, ans = 0;
    for (int apartment_pointer = 0; apartment_pointer < m; apartment_pointer++) {
        // increment applicant_pointer until it is >= required value
        // this works as any apartment_pointer after this will not be compatable with any person before
        // this as the person before this would be less; these arrays are sorted.
        while (p[applicant_pointer] < rooms[apartment_pointer] - k && applicant_pointer < n) {applicant_pointer++;}
        
        // if this person is compatible, then add to ans and increment pointer
        if (abs(p[applicant_pointer] - rooms[apartment_pointer]) <= k) {
            ans++;
            applicant_pointer++;
        }
    
        // increment apartment_pointer pointer even if not compatible
        // if this apartment_pointer isn't compatable with this person, it wont be compatable with any
        // one else before, or after
    }
    cout << ans << endl;
}