#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int l, r; cin >> l >> r;

    int best = 0;
    int num = l;
    string s;
    rep(i,l,min(l+100,r+1)) {
      s = to_string(i);
      sort(s.begin(), s.end());
      if ((s[s.size()-1] - '0') - (s[0] - '0') > best) {
        best = (s[s.size()-1] - '0') - (s[0] - '0');
        num = i;
      }
    }

    cout << num << '\n';

  }
}
