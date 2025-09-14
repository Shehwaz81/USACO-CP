#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

struct rect {
    int x1, x2, y1, y2;
    void read() {cin >> x1 >> y1 >> x2 >> y2;} 
};

int main() {
    rect a, b;
    // process input
    a.read(), b.read();
    // find max hieght/length of billboard after overlap
    int maxH, maxW;
    int ox = min(a.x2, b.x2) - max(a.x1, b.x1);
    int oy = min(a.y2, b.y2) - max(a.y1, b.y1);
    if (ox < b.x2 - b.x1) {maxH = b.y2 - b.y1;} // if length doesn't span the whole billboard, then you will need a tarp of max height at least to cover it
    else {
        if (b.y1 < a.y1 && b.y2 < a.y2) {maxH = }
    }
}