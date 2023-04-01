#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;

int main() {
  int n, d; cin >> n >> d;
  ll t = 0, r = 0;
  t = 10*n;
  r = 10*n;
  r %= d;
  r *= 10;

  while (t != r) {
    t %= d;
    t *= 10;
    r %= d;
    r *= 10;
    r %= d;
    r *= 10;
  }

  r = 10*n;
  t %= d;
  t *= 10;
  int mu = 0, lambda = 0;
  while (t != r) {
    t %= d;
    t *= 10;
    r %= d;
    r *= 10;
    ++mu;
  }
  if (t != 0) {
    lambda = 1;
    r %= d;
    r *= 10;
    while (t != r) {
      r %= d;
      r *= 10;
      ++lambda;
    }
  }

  cout << mu << " " << lambda;


}
