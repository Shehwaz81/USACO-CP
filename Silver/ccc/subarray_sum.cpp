#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> pref_freq;
    int sum = 0, ans = 0;
    pref_freq[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        ans += pref_freq[sum - k];
        pref_freq[sum]++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = subarraySum(nums, k);

    cout << ans << endl;
    return 0;
}
