#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;

int main() {
  int n, k, m; cin >> n >> k >> m;
  vector<int> num(n, 0);
  int ans = 0;
  rep(i, 0, n*k+1) {
    cerr << "------" << endl;
    cerr << i << endl;
    ll sum = 0;
    rep(i, 0, n) {
      sum += num[i];
      sum %= m;
    }

    ll tmp = 0;
    bool found = false;
    rep(i, 0, n) {
      tmp = sum - 2*num[i];
      tmp = (tmp+m)%m;
      if (tmp == 0) {
        found = true;
        cerr << "found: " << i << endl;
        rep(i, 0, n) {
          cerr << num[i] << " ";
        }
        cerr << endl;
        break;
      }
    }
    if (found) {
      ++ans;
    }

    
    int z = 0;
    while (true) {
      num[z]++;
      if (num[z] >= k) {
        num[z] = 0;
        ++z;
        continue;
      }
      break;
    }
  }
  cout << ans;
}
