#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

int main() {
  int n, k; cin >> n >> k;
  vector<int> v;
  v.assign(n, 0);
  rep(i, 0, n) {
    cin >> v[i];
  }

  int cnt;
    cnt = 0;
  rep(i, 0, n-k+1) {
    rep(j, 0, k/2) {
      cerr << v[i+j] << " " << v[i+k-1-j] << endl;
      if (v[i+j] != v[i+k-1-j]) ++cnt;
    }
    cerr << "-----------" << endl;
    
  }
  cout << cnt;
}
