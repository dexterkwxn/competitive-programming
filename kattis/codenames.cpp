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
    vis[R] = 1;
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      match[L] = R;                              // flip status
      freeV.erase(R);
      return 1;                                  // found 1 matching
    }
    vis[R] = 0;
  }
  return 0;                                      // no matching
}

int main() {
  int n; cin >> n;
  vector<string> v(n);
  rep(i, 0, n) {
    cin >> v[i];
  }
  int sz = v[0].size();

  AL.assign(n, {});
  string s, t;
  set<int> st;
  bool flag = true;
  rep(i, 0, n) {
    s = v[i];
    rep(j, i+1, n) {
      t = v[j];
      st.clear();
      flag = true;
      rep(k, 0, sz) {
        if (s[k] != t[k]) {
          if (st.size() > 1) {
            flag = false;
            break;
          }
          st.insert(k);
        }
      }
      if (flag) {
        AL[i].pb(j);
        AL[j].pb(i);
      }
    }
  }

  rep(i, 0, n) {
    freeV.insert(i);
  }
  match.assign(n, -1);
  int MCBM = 0;
  // Greedy pre-processing for trivial Augmenting Paths
  // try commenting versus un-commenting this for-loop
  for (int L = 0; L < n; ++L) {              // O(V+E)
    vi candidates;
    if (freeV.find(L) == freeV.end()) continue;
    for (auto &R : AL[L])
      if (match[R] == -1)
        candidates.push_back(R);
    if ((int)candidates.size() > 0) {
      ++MCBM;
      freeV.erase(L);                            // L is matched
      int a = rand()%(int)candidates.size();     // randomize this
      freeV.erase(candidates[a]);                            // L is matched
      match[candidates[a]] = L;
      match[L] = candidates[a];
    }
  }                                              // for each free vertex
  for (auto &f : freeV) {                        // (in random order)
    vis.assign(n, 0);                        // reset first
    MCBM += Aug(f);                              // try to match f
  }
  cout << n - MCBM;

  return 0;
}

