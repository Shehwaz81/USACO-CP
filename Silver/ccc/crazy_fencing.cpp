#include <bits/stdc++.h>
using namespace std;
using ld = long double;

vector<int> a, b;

int main() {
    int n; cin >> n;

    vector<int> vert(n + 1), hori(n); // vectors to store all lengths
    for (int i = 0; i <= n; i++) {cin >> vert[i];}
    for (int i = 0; i < n; i++) {cin >> hori[i];}

    // go through vert, and get hieght of each quadralaterial made
    ld area = 0;
    for (int i = 0; i < n; i++) { // we only go upto n - 1 to avoid out of bounds error. 
        // we do vert[i] as left height, and vert[i + 1] as right height, and width as the ith hori
        ld l = vert[i], r = vert[i + 1], w = hori[i];

        // calc area of sqaure inside shape
        area += (min(l, r) * w);

        // calculate area of the top (triangle)
        ld offset = (ld)abs(l - r);
        if (offset > 0) area += (offset * w) / 2.0;
    }

    cout << fixed << setprecision(1) << area << endl;
}