#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using ld = long double;

int main() {
    string s; cin >> s;
    
    vector<vector<int>> arr = {{1, 2}, {3, 4}};
    for (char ch : s) {
        int a = arr[0][0], b = arr[0][1], c = arr[1][0], d = arr[1][1];
        if (ch == 'H') {
            swap(a, c);
            swap(b, d);
            arr = {{a, b}, {c, d}};
        } else {
            swap(a, b);
            swap(c, d);
            arr = {{a, b}, {c, d}};
            
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}