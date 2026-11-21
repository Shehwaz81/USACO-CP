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

void solve(int x, vector<int>& coins) {
	
	vector<int> dp(x + 1, 1e9); // all inf initially
	dp[0] = 0; // base case
	vector<int> first(x + 1);
	
	for (int i = 1; i <= x; i++) {
		for (auto& c : coins) {
			if (i - c >= 0 && dp[i - c] + 1 < dp[i]) {
				// if the sum is >= 0 and value[i - c] + 1 is less than
				// the current min value of x, then we update the minimum
				// value[x], and update first array
				dp[i] = dp[i - c] + 1;
				first[i] = c; // update with the COIN, not the dp[i]. We want the first optimal COIN!
			}
		}
	}
	
	// print answer
	if (dp[x] == 1e9) {
		cout << -1 << endl;
        return;
	}
	while (x > 0) {
		cout << first[x] << ' '; // print the first optimal coin
		x -= first[x]; // subtract the first optimal coin to move forward in the construction (to print the next optimal coin for sum x - first optimal coin)
	}
}

int main() {
    int n, x; cin >> n >> x;

    vector<int> coins(n );
    for (int& c : coins) {cin >> c;}

    solve(x, coins);

}