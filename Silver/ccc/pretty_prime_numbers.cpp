#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ld = long double;

bool isPrime(int x) {
    int t = sqrt(x) + 1;
    if (x == 1) {return false;}
    if (x == 2) {return true;}
    for (int i = 2; i <= t; i++) {
        if (x % i == 0) {return false;}
    }
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x = n*2;
        
        if (isPrime(x - 2)) {cout << 2 << ' ' << x - 2 << endl; continue;}
        
        // using the fact that (a + b) / 2 = n if a + b = 2n
        for (int i = 3; i <= n; i+=2) {
            if (isPrime(i) && isPrime(x - i)) {
                cout << i << ' ' << x - i << endl;
                break;
            }
        }
        
        // no need to check if answer was found since it is garenteed
    }
}