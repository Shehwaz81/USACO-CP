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


// we will use a double hash system to minimize the risk of hash collision

const ll BASEA = 131, BASEB = 137; // prime numbered base
const ll MA = 1e9 + 7, MB = 1e9 + 9; // prime numbered mod

int main() {
    string n, h; cin >> n >> h;
    set<pair<ll, ll>> distinct; // keep track of all distinct n's
    
    // get the freq of chars in string n;
    vector<ll> freq(26, 0);
    for (char c : n) {freq[c - 'a']++;}

    // calc max_power we have to multiply by to remove the last char from the hash
    ll hashA = 0, hashB = 0;
    ll max_powA = 1, max_powB = 1;
    for (ll i = 0; i < n.size() - 1; i++) {
        max_powA = (max_powA * BASEA) % MA;
        max_powB = (max_powB * BASEB) % MB;
    }

    // initial hash and freq to mantain
    vector<ll> new_freq(26, 0);
    for (ll i = 0; i < n.size(); i++) {
        hashA = ((hashA * BASEA) + (h[i] - 'a' + 1)) % MA;
        hashB = ((hashB * BASEB) + (h[i] - 'a' + 1)) % MB;
        new_freq[h[i] - 'a']++;
    }
    if (new_freq == freq) {distinct.insert({hashA, hashB});}

    // sliding window mantaining a window of n.size();
    ll sn = n.size(), sh = h.size();
    for (ll i = sn; i < sh; i++) {
        // remove prev char
        ll left_hashA = ((h[i - sn] - 'a' + 1) * max_powA) % MA;
        ll left_hashB = ((h[i - sn] - 'a' + 1) * max_powB) % MB;
        hashA = (hashA - left_hashA + MA) % MA;
        hashB = (hashB - left_hashB + MB) % MB;

        // add new char to hash (A and B)
        hashA = ((hashA * BASEA) + (h[i] - 'a' + 1)) % MA;
        hashB = ((hashB * BASEB) + (h[i] - 'a' + 1)) % MB;

        // update freq
        new_freq[h[i - sn] - 'a']--;
        new_freq[h[i] - 'a']++;

        // add to set if 
        if (freq == new_freq) distinct.insert({hashA, hashB});
    }
    
    ll d = distinct.size();
    cout << d << endl;
}