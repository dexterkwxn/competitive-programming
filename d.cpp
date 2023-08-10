#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"
typedef long long ll;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> a, b;
        rep(i, 0, n) { cin >> v[i]; }
        int ans = 0;
        rep(i, 0, n - 1) {
            int d = v[i + 1] % v[i];
            if (v[i + 1] % v[i])
                continue;
            a[d]++;
        }
        cout << ans << nl;
    }
}
