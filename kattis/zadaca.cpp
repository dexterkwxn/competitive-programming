#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
unordered_map<int, int> umpa, umpb;
#define rep(i, a, n) for(int i = a; i < n; ++i)

void factorise(ll n, unordered_map<int, int>& ump) {
  bool isprime = true;
  if (n == 2) {
    ++ump[2];
    return;
  }
  while (n % 2 == 0) {
    isprime = false;
    ++ump[2];
    n /= 2;
  }
  for (ll d = 3; d * d <= n; d += 2) {
    while (n % d == 0) {
      isprime = false;
      ++ump[d];
      n /= d;
    }
  }
  if (n > 1) ++ump[n];
  return;
}

int main() {
  int n, m, k;
  cin >> n;
  rep(i, 0, n) {
    cin >> k;
    factorise(k, umpa);
  }
  cin >> m;
  rep(i, 0, m) {
    cin >> k;
    factorise(k, umpb);
  }
  ll gcd = 1;
  for (auto&[k,v]:umpa) {
    if (umpb.find(k) != umpb.end()) {
      ll exp = min(v, umpb[k]);
      while (exp--) {
        gcd *= k;
        gcd %= (ll) 1e10;
      }
    }
  }
  string s = to_string(gcd);
  if (s.length() > 9) {
    s = s.substr(s.length() - 9);
  }
  cout << s;
  return 0;
}
