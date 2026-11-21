#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    int a, b, x, y; cin >> a >> b >> x >> y;

    // case 1 when they are next to each other
    int p1 = 2*(a + x) + 2 * max(b, y);

    // case 2 is when they are stacked ontop of each other
    int p2 = 2*(b + y) + 2*max(a, x);


    cout << min(p1, p2) << endl;
}