#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int f = 0;
    // since we are using pairs, start from n - 2 so we can use substr(i, 2), then update i with i = i - 2 every time as we can only reverse on even indicies
    for (int i = n - 2; i >= 0; i -= 2) {
        string pair = s.substr(i, 2);
        // if the pair is "GH" and it has been flipped an EVEN amt of times, the pair is missaligned and we must reverse the prefix up to this pair.
        // if the pair is "HG" and it has been flipped an ODD amt of times, the pair is also missaligned and we must flip, or reverse the prefix up to this point.
        if ((pair == "GH" && (f % 2 == 0)) || (pair == "HG" && (f % 2 == 1))) {f++;}
    }
    cout << f << endl;
}