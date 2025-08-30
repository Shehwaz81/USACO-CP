#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;


int main() {
    int n; cin >> n;
    int type[2]{};
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        type[val % 2]++;
    }
    // A single leftover odd cannot form a valid even-sum group. 
    // To avoid this, pair up odds into "fake evens" (two odds = one even) 
    // until odds <= evens. 
    // You also cannot have a single odd left over, as you wouldn't be able to add it to any group without fipping the parity
    while (type[1] > type[0]) {
        type[1] -= 2;
        type[0]++;
    }
    if (type[0] > type[1]) {cout << (type[1] * 2) + 1 << endl; return 0;} // if there are less odds than even, we can only have so much as "the amount of odds left * 2" representing 0 1 (odd even pair) plus one final even, as you can add a final even after you do (even ODD and then another even)
    cout << type[0] + type[1] << endl; // this is if they are equal, meaning after they make the odd even sequence, there are none evens or odds left over to add, so just output odd + even! 
}