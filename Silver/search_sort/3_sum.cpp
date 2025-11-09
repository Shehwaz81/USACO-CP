#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    // use one int of a pair to store the value, and the other to store the original index of that value
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i].first; a[i].second = i;}
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1, required_sum = x - a[i].first; // required sum is how much we need a[l] and a[r] to add up to
        while (l < r) {
            int current_sum = a[r].first + a[l].first;
            if (i != r && i != l && current_sum == required_sum) {
                cout << a[i].second + 1 << ' ' << a[l].second + 1 << ' ' << a[r].second + 1 << endl;
                return 0;
            } else if (current_sum < required_sum) {l++;}
            else if (current_sum > required_sum) {r--;}
        }
    }
    cout << "N/A" << endl;
}