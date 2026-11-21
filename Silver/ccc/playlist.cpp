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
    int n; cin >> n;
    
    vector<int> nums(n);
    map<int, int> seen;
    
    for (int i = 0; i < n; i++) {cin >> nums[i];}
    
    int l = 0, s = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        // check if we have seen this num before;
        while (seen[nums[r]] > 0 && l < r) {
            seen[nums[l]] = 0;
            s--;
            l++;
        }
        s++;
        seen[nums[r]] = true;

        ans = max(s, ans);
    }
    cout << ans << endl;
}