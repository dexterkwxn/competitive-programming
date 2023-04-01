#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define nl "\n"
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(int i=a; i<b; i++)

vi match, vis;                                   // global variables
vector<vi> AL;
unordered_set<int> freeV;

int Aug(int L) {
  if (vis[L]) return 0;                          // L visited, return 0
  vis[L] = 1;
  for (auto &R : AL[L]) {
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      return 1;                                  // found 1 matching
    }
  }
  return 0;                                      // no matching
}

int main() {
  int t; cin >> t;
  while (t--) {
    AL.clear();
    freeV.clear();
    match.clear();
    int n; cin >> n;
    AL.assign(3*n+1, {}); // try repeat nodes
    int p, q;
    rep(i, 1, n+1) {
      cin >> p >> q;
      AL[i].pb(n+p);
      AL[i].pb(n+q);
      freeV.insert(i);
    }

    match.assign(3*n+1, -1);
    int MCBM = 0;
    // Greedy pre-processing for trivial Augmenting Paths
    // try commenting versus un-commenting this for-loop
    for (int L = 1; L <= n; ++L) {              // O(V+E)
      vi candidates;
      for (auto &R : AL[L])
        if (match[R] == -1)
          candidates.push_back(R);
      if ((int)candidates.size() > 0) {
        ++MCBM;
        freeV.erase(L);                            // L is matched
        int a = rand()%(int)candidates.size();     // randomize this
        match[candidates[a]] = L;
      }
    }                                              // for each free vertex
    for (auto &f : freeV) {                        // (in random order)
      vis.assign(n+1, 0);                        // reset first
      MCBM += Aug(f);                              // try to match f
    }
    cout << (MCBM == n ? "possible" : "impossible") << nl;
  }
  return 0;
}

