
// My false attempt at question C      (AtCoder Beginner Contest 459)
int main() {
    int n, q; cin >> n >> q;
    vector<int> c(n, 0), suff(n + 1, 0);
    suff[0] += n;

    int blocks_with_one = 0, offset = 0;
    map<int, int> freq; freq[0] = n; // tracks how many cells have i blocks
    while (q--) {
        int type, x; cin >> type >> x;
        if (type == 1) {
            x--; // 0 indexed
            if (c[x] == 0) {blocks_with_one++;}
            if (blocks_with_one == n) {
                offset++;
            } else {
                freq[c[x]]--;
                freq[++c[x]]++;
                suff[c[x]]++;
            }
        } if (type == 2) {
            if (x == 0) {cout << n << endl; continue;}
            int r = x + offset;
            int l = x;
            if (l < 0) l = 1; // block amt can never be less than 0
            int amt = suff[l] - suff[r];
            cout << suff[l] - amt << endl;
        }
    }
}