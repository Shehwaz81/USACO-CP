#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

bool divisor(int a, int b) {
    if (a % b == 0) {return true;}
    if (b % a == 0) {return true;}
    
    int max_divisor = min(sqrt(a), sqrt(b));

    int ans = 1;
    for (int i = 2; i <= max_divisor; i++) {
        if (a % i == 0 && b % i == 0) {
            return true;
        }
    }

    return false;

}

int main() {
    int n; cin >> n;

    vector<int> cards(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        sum += cards[i];
    }

    int a = 0, b = sum;

    
    vector<int> alice;
    vector<int> bob = cards;

    bool valid = false;
    for (int i = 0; i < n; i++) {
        a += cards[i];
        alice.push_back(cards[i]);

        b -= cards[i];
        bob.erase(find(bob.begin(), bob.end(), cards[i]));

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            b -= cards[j];
            alice.push_back(cards[j]);

            a += cards[j];
            bob.erase(find(bob.begin(), bob.end(), cards[j]));

            if (divisor(a, b)) {
                valid = true;
                goto found;
            }

            alice.erase(find(bob.begin(), bob.end(), cards[j]));
            bob.push_back(cards[j]);

            b += cards[j];
            a -= cards[j];


        }

        bob.push_back(cards[i]);
        b+= cards[i];

        alice.erase(find(bob.begin(), bob.end(), cards[i]));
        a-= cards[i];        
    }


    found:

    if (valid) {
        cout << "YES" << endl;
        for (int i : alice) {cout << i << ' ';}
        cout << endl;

        for (int i : bob) {
            cout << i << ' ';
        }
        cout << endl;

    } else {
        cout << "NO" << endl;
    }
}