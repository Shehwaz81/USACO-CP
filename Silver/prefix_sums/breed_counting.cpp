#include <bits/stdc++.h>
using namespace std;

struct breed {
    int a = 0, b = 0, c = 0;
};

int main() {
    int n, q; cin >> n >> q;
    vector<breed> b(n + 1);

    for (int i = 1; i <= n; i++) {
        int cow; cin >> cow;
        if (cow == 1) {b[i].a++;}
        else if (cow == 2) {b[i].b++;}
        else {b[i].c++;}
        b[i].a += b[i - 1].a;
        b[i].b += b[i - 1].b;
        b[i].c += b[i - 1].c;
    }

    for (int i = 0; i < q; i++) {
        int start, end; cin >> start >> end;
        cout << b[end].a - b[start - 1].a << ' ' << b[end].b - b[start - 1].b << ' ' << b[end].c - b[start - 1].c << endl;
    }
}