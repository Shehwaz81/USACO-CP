#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> day(n, 0), counter(n, 0);
    // we know day 1 there definately was a breakout
    day[0] = 1;
    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        counter[i] = c;
        if (c > -1) {
            if (i - c < 0) {cout << "-1" << endl; return 0;}
            // we know that if counter says x, anything in between  i - x and i is NOT a breakout day;
            int ind = i;
            while(ind != i - c) {
                if (day[i] == 1) {cout << "-1" << endl; return 0;}
                day[ind] = 0;
                ind--;
            }
            if (counter[ind] > 0) {cout << "-1" << endl; return 0;}
            day[ind] = 1;
        } else if (c == -1) {
            // we can label this day as uncertain, until proven not
            if (day[i] != 1) day[i] = -1;
        }
    }
    int m = 0, M = 0;
    for (int& i : day) {
        if (i == 1) {m++; M++;}
        else if (i == -1) {M++;}
    }
    cout << m << ' ' << M << endl;
    

    return 0;
}