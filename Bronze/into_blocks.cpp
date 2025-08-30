 #include <bits/stdc++.h>
 using namespace std;
 #define all(x) (x).begin(), (x).end()

int main() {
    int n, q; cin >> n >> q; // q is unused
    map<int, vector<int>> index;
    for (int i = 0; i < n; i++) {
        int value; cin >> value;
        index[value].push_back(i); // add indicie to that value
    }
    vector<vector<int>> interval;
    for (auto &[value, indicie] : index) {
        // we need to store the start, end, and amt of values in this range
        interval.push_back({indicie[0], indicie[indicie.size() - 1], (int)indicie.size()});
    }
    // sort intervals from start position, as they are not garenteed to be so
    sort(all(interval));
    int dif = 0, s = interval[0][0], e = interval[0][1], mostFreq = interval[0][2];
    for (auto & i : interval) {
       if (i[0] > e) { // if the intervals or ranges dont overlap, and start is strictly more than end
           dif += (e - s + 1) - mostFreq;
           s = i[0];
           e = i[1];
           mostFreq = i[2];
       } else {
           e = max(e, i[1]);
           mostFreq = max(mostFreq, i[2]);
       }
    }
    // contribute difficulty one last time as last segment is not contributed (iteration ends)
    dif += (e - s + 1) - mostFreq;
    
    cout << dif << endl;

    return 0;
}