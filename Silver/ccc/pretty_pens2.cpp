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
using p = pair<int, int>;

int n, m, q;
ll sum = 0;
vector<set<p, greater<p>>> color(200001);
multiset<int> top1, top2;
vector<p> pen(200001); // it is pen{color, prettiness}

void change_p(int i, int p) {
    int c = pen[i].first, old_p = pen[i].second;
    pen[i].second = p; // set prettiness of pen[i] to new prettiness value

    // erase the old top1 and top2 colors
    top1.erase(top1.find(color[c].begin()->first));
    top2.erase(top2.find((++color[c].begin())->first));
    sum -= color[c].begin()->first;

    // erase old instance and insert new
    color[c].erase({old_p, i});
    color[c].insert({p, i});
 
    // update color multiset
    int new_first = color[c].begin()->first;
    int new_second = (++color[c].begin())->first;
    sum += new_first;

    // update top1 and top2
    top1.insert(new_first);
    top2.insert(new_second);

    return;
}

void change_c(int i, int c) {
    int old_c = pen[i].first, p = pen[i].second;
    pen[i].first = c; // update color of pen i
    
    // remove from top1 and top2 from BOTH colors
    if (color[c].size() > 0) top1.erase(top1.find(color[old_c].begin()->first));
    if (color[c].size() > 1) top2.erase(top2.find((++color[old_c].begin())->first));
    if (color[c].size() > 0) top1.erase(top1.find(color[c].begin()->first));
    if (color[c].size() > 1) top2.erase(top2.find((++color[c].begin())->first));

    // update sum
    sum -= (color[old_c].begin()->first + color[c].begin()->first);

    // remove from color and insert into new color
    color[old_c].erase({p, i});
    color[c].insert({p, i});

    // add new top1 and top2 for both colors
    int new_first_c = color[c].begin()->first;
    int new_second_c = (++color[c].begin())->first;
    int new_first_old_c = color[old_c].begin()->first;
    int new_second_old_c = (++color[old_c].begin())->first;
    top1.insert(new_first_c), top2.insert(new_second_c);
    top1.insert(new_first_old_c), top2.insert(new_second_old_c);

    // update sum
    sum += new_first_c + new_first_old_c;
}

int main() {
    cin >> n >> m >> q;

    pen.resize(n + 1);
    // insert an out of bound value in case we try to find 2nd best, and there is none
    for (int i = 1; i <= m; i++) {color[i].insert({0, 0});}

    for (int i = 1; i <= n; i++) {
        int c, p; cin >> c >> p;
        color[c].insert({p, i});
        pen[i] = {c, p};
    }
    
    // establish top1 and top2 and global sum
    for (int i = 1; i <= m; i++) { 
        // best prettiness of color i MUST be apart of sum initially
        sum += color[i].begin()->first;

        top1.insert(color[i].begin()->first);
        top2.insert((++color[i].begin())->first); // insert second best prettiness (0 out of bound if not enough pens)
    }

    // the final max sum is the sum of all top1 values, plus if we were to take the least top1 value and replace it with the highest top2 value of any pen (or 0 if top1 min > top2 max)
    cout << sum + max(0, *(--top2.end()) - *top1.begin()) << endl;

    while (q--) {
        int t, i, v; cin >> t >> i >> v;
        if (t == 2) {
            change_p(i, v);
            cout << sum + max(0, *(--top2.end()) - *top1.begin()) << endl;
        } else {
            change_c(i, v);
            cout << sum + max(0, *(--top2.end()) - *top1.begin()) << endl;
        }
    }
}