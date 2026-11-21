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
    int t, n; cin >> t >> n;

    while (t--) {
        string s; cin >> s;

        // keep track of freq of all chars in a vector (O(1) lookup time)
        vector<int> freq(26, 0);
        
        // compute freq of each char
        for (char c : s) {freq[c - 'a']++;}

        // let false be light, let true be heavy
        bool prev = freq[s[0] - 'a'] != 1;

        // go through the string, as see if each char is alternating
        bool valid = true;
        for (int i = 1; i < n; i++) {
            // see if curr char is light or heavy
            int idx = s[i] - 'a';
            bool curr = freq[idx] != 1;
            
            if (curr == prev) {valid = false; break;}

            prev = curr;
        }

        cout << (valid ? 'T' : 'F') << '\n';
    }
}