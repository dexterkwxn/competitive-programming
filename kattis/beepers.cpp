#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"

vector<pair<int, int>> v;
int sx, sy;
int n;
ll all;

int tsp(ll mask, int cur) {
    mask |= 1 << cur;
    if (mask == all) {
        return abs(v[cur].first - sx) + abs(v[cur].second - sy);
    }

    int best = INT_MAX;
    int cost;
    rep(i, 0, n) {
        if ((mask & (1 << i)) == 0) {
            cost = abs(v[i].first - v[cur].first) +
                   abs(v[i].second - v[cur].second);
            cost += tsp(mask, i);
            best = min(best, cost);
        }
    }
    cerr << "cur: " << cur << ", best: " << best << nl;
    return best;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int w, h;
        cin >> w >> h;
        cin >> sx >> sy;
        cin >> n;

        all = (1 << n) - 1;
        v.assign(n, {});

        int x, y;
        rep(i, 0, n) {
            cin >> x >> y;
            v[i] = {x, y};
        }

        int best = INT_MAX;
        int cost;
        rep(i, 0, n) {
            cost = abs(v[i].first - sx) + abs(v[i].second - sy);
            cost += tsp(0, i);
            best = min(best, cost);
            cerr << "i: " << i << ", best: " << best << nl;
        }
        cout << best << nl;
    }
}
