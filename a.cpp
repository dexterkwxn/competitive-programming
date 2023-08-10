#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, t;
        cin >> n >> t;
        vector<int> d(n), e(n);
        rep(i, 0, n) { cin >> d[i]; }
        rep(i, 0, n) { cin >> e[i]; }

        int run = -1;
        int best = -1;
        rep(i, 0, n) {
            if (d[i] + i <= t) {
                if (e[i] > best) {
                    run = i + 1;
                    best = e[i];
                }
            }
        }
        cout << run << nl;
    }
}
