#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

// make a struct to store all info and possible functions of a rectangle
struct rect {
    int x1, x2, y1, y2;
    void r() {cin >> x1 >> y1 >> x2 >> y2;}
    int a() {return (x2 - x1) * (y2 - y1);}
};

int main() {
    rect a, b, t;
    // read all inputs
    a.r(); b.r(); t.r();
    // get x and y overlap;
    int oxa = min(a.x2, t.x2) - max(a.x1, t.x1), oya = min(a.y2, t.y2) - max(a.y1, t.y1);
    int oxb = min(b.x2, t.x2) - max(b.x1, t.x1), oyb = min(b.y2, t.y2) - max(b.y1, t.y1);

    // print overlap, if ox or oy are negative or 0, it means that there is either no overlap or they are just touching
    int oA = (oxa * oya), oB = (oxb * oyb);
    if (oxa <= 0 || oya <= 0) {oA = 0;}
    if (oxb <= 0 || oyb <= 0) {oB = 0;}
    int total = oA + oB;
    cout << (a.a() + b.a()) - total << endl;
}