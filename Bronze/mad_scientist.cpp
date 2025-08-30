#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int n; cin >> n;
    string original, altered; cin >> original >> altered;
    int alt_amt = 0;
    for (int i = 0; i < n; i++) {
        if (original[i] != altered[i]) {
            // finds how long the incorrect substring is
            while (i < n && original[i] != altered[i]) {i++;}
            alt_amt++;
        }
    }
    cout << alt_amt << endl;
}