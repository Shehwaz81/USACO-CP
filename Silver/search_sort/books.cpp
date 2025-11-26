	#include <vector>
	#include <iostream>
	using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, T;
	cin >> N >> T;
	vector<int> a(N);
	for (int &i : a) cin >> i;

	int r = 0, sum = 0, ans = 0;
	// sum stores sum of A[l ... r inclusive]
	for (int l = 0; l < N; l++) {
		while (r < N && sum + a[r] <= T) sum += a[r++];
		ans = max(ans, r - l);
		sum -= a[l];
	}
	cout << ans << "\n";
}