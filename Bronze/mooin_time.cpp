#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end();
using namespace std;

bool is_moo(string m) {
    if (m[0] != m[1] && m[1] == m[2]) return true;
    return false;
}

int main() {
    int n, f; cin >> n >> f;
    string s; cin >> s;

    map<string, int> freq;
    set<string> poss;
    // get frequency of all moos originally
    for (int i = 0; i < n - 2; i++) {
        string moo = s.substr(i, 3);
        if (is_moo(moo)) freq[moo]++;
    }
    // insert any moos that are above threshold
    for (auto &[moo, t] : freq) {
        if (t >= f) poss.insert(moo);
    }

    // now, see if altering anything would change anything
    for (int i = 0; i < n; i++) {
        string sCopy = s;
        // go through and update temp freq for this letter replacement of index i
        for (char c = 'a'; c <= 'z'; c++) {
            map<string, int> tmp_freq;
            sCopy[i] = c;
            for (int j = 0; j < n - 2; j++) {
                string moo = sCopy.substr(j, 3);
                if (is_moo(moo)) tmp_freq[moo]++;
            }

            for (auto &[m, t] : tmp_freq) {
                if (t >= f) {poss.insert(m);}
            }
        }
    }
    cout << (int)poss.size() << endl;
    // print all poss moos in lexographical order
    for (string m : poss) {
        cout << m << endl;
    }
}