#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;

int main() {
  int tc; cin >> tc;
  while (tc--) {
    ll l, r; cin >> l >> r;
    ll num = l;
    string s = to_string(l);
    unordered_map<int, set<int>> ump;

    rep(i, 0, s.size()) {
      ump[s[i]-'0'].insert(i);
    }

    string cp = s;
    sort(cp.begin(), cp.end());
    while (true) {
      while (true) {
        int digit = cp[0] - '0';
        int pos = *ump[digit].rbegin();
        s[pos]++;
        if (stoi(s) > r) break;
        rep(j, 0, s.size()-1) {
          if (cp[j] > cp[j+1]) swap(cp[j], cp[j+1]);
        }
      }
      while (true) {
        int digit = cp[cp.size()-1] - '0';
        int pos = *ump[digit].rbegin();
        s[pos]--;
        if (stoi(s) < l) break;
        for (int j = s.size()-1; j > 0; --j) {
          if (cp[j] > cp[j-1]) swap(cp[j], cp[j-1]);
        }
      }
      break;
    }

    cout << stoi(s) << '\n';

  }
}
