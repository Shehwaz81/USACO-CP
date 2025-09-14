#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> y(n), x(n);
    for (int i = 0; i < n; i++) {cin >> x[i] >> y[i];}

    sort(all(x)), sort(all(y));
    // store greatest and least 4 x's and y's
    vector<int> maxX(x.end(), x.end() - 4), minX(x.begin(), x.begin() + 4);
    vector<int> maxY(y.end(), y.end() - 4), minY(y.begin(), y.begin() + 4);

    // now, check all possibilities and see which results in least area
    int best = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int miX = minX[0], maX = maxX[0], miY = minY[0], maY = maxY[0];
        if (i == 3) {
            miX = minX[i];
            int area = (maX - miX) * (maY - miY);
            best = min(area, best);
            continue;
        } else {miX = minX[i];}
        for (int j = i; j < 4; j++) {
            if (j == 3) {
                maX = maxX[j];
                int area = (maX - miX) * (maY - miY);
                best = min(area, best);
                continue;
            } else {maX = maxX[j];}
            for (int k = j; k < 4; k++) {
                if (k == 3) {
                    miY = minY[k];
                    int area = (maX - miX) * (maY - miY);
                    best = min(area, best);
                    continue;
                } else {miY = minY[k];}
                for (int l = k; l < 4; l++) {
                    if (l == 3) {
                        maY = maxY[l];
                        int area = (maX - miX) * (maY - miY);
                        best = min(area, best);
                        continue;
                    } else {maY = maxY[l];}
                }
            }
        }
    }
    cout << best << endl;
}