#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

unordered_map<ll, ll> ump;

bool factorise(ll n) {
  bool isprime = true;
  if (n == 2) {
    ++ump[2];
    return true;
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
  return isprime;
}

int main() {
  ll a, b; cin >> a >> b;
  bool ap = factorise(a);
  bool bp = factorise(b);
  if (ap && bp && a != b) {
    cout << "full credit\n";
    return 0;
  }
  for (auto& [k, v] : ump) {
    if (v > 1) {
      cout << "no credit\n";
      return 0;
    }
  }
  cout << "partial credit\n";
  return 0; 
}
