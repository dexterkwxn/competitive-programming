#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        cout << fixed << setprecision(0) << n * n + 2 * n + 2 << nl;
    }
}
