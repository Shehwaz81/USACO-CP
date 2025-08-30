#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end()
using namespace std;

struct rect {
    int x1, x2, y1, y2;
    void read() {cin >> x1 >> y1 >> x2 >> y2;}
};

int main() {
    rect a, b;
    // process inputs
    a.read(), b.read();
    // find the lower minimum x and y
    int minX = min(a.x1, b.x1), minY = min(a.y1, b.y1);
    // find the upper maximum of x and y
    int maxX = max(a.x2,b.x2), maxY = max(a.y2,b.y2);
    
    // get the minimum side dimension of the sqaure pasture that covers everything
    int side = max(maxX - minX, maxY - minY);

    cout << side * side << endl;
}