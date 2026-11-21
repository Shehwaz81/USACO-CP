#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int lastTrue(int low, int high, function<bool(int)> f) {
	low--; // we will output 1 less than original low if no answer
	while (low < high) {
		int mid = low + (high - low + 1) / 2; // use + 1 for finding LAST
		if (f(mid)) {
			// all previous values also must work, so we must search right for a better answer
			low = mid;
		}
		else {
			// we must search to the left for a valid answer
			high = mid - 1;
		}
	}
    return low;
}

int main() {
	cout << lastTrue(2, 10, [](int x) {return true;}) << endl;
	cout << lastTrue(2, 10, [](int x) {return x * x <= 30;}) << endl;
	cout << lastTrue(2, 10, [](int x) {return x == 2;}) << endl;
    return 0;
}