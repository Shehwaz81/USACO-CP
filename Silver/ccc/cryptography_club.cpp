#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <cctype>
using namespace std;
using ll = long long;
using p = pair<char, ll>;

int main() {
    string s; cin >> s;

    ll n = s.size();
    vector<p> a;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        p curr;
        if (isalpha(s[i])) {curr.first = s[i++];}
        string num = "";

        while (isdigit(s[i])) {
            num += s[i];
            i++;
        }
        i -= 1; // go back one as this is the NEXT pair
        curr.second = stoi(num);

        a.push_back(curr);
        sum += curr.second;
    }

    ll c; cin >> c;

    c %= sum;

    ll idx = 0;
    for (auto [ch, i] : a) {
        idx += i;
        if (c < idx) {
            cout << ch << endl;
            return 0;
        }
    }
}