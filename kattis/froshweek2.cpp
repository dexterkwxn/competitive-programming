#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n), v(m);
    rep(i, 0, n) { cin >> t[i]; }
    rep(i, 0, m) { cin >> v[i]; }
    sort(t.begin(), t.end());
    sort(v.begin(), v.end());

    int i = 0, j = 0;
    int ct = 0;
    while (i < n && j < m) {
        if (t[i] <= v[j]) {
            ++ct;
            ++i;
        }

        ++j;
    }
    cout << ct;
}
