#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;

int main() {
  int tc; cin >> tc;

  while (tc--) {
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    vector<vector<ll>> v;
    v.assign(m, vector<ll>(n));
    rep(i, 0, n) {
      rep(j, 0, m) {
        cin >> v[j][i];
      }
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    rep(i, 0, m) {
      sort(v[i].rbegin(), v[i].rend());
    }
    vector<ll> vv;
    vv.assign(n, 0);
    rep(i, 0, n) {
      rep(j, 0, m) {
        vv[i] += v[j][i];
      }
    }
    ll cur = vv[n-1];
    for (int i = n-2; i >= 0; --i) {
      sum += (n-i-1)*vv[i] - cur;
      cur += vv[i];
    }
    cout << sum << '\n';
  }
}
