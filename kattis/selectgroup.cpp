#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

string s, x, name;
vector<string> out;
int n;
unordered_map<string, vector<string>> ump;

vector<string> op(string operation) {
  string a, b;
  vector<string> va, vb, ret;
  cin >> a;
  if (ump.find(a) == ump.end()){
    va = op(a);
  } else {
    va = ump[a];
  }
  cin >> b;
  if (ump.find(b) == ump.end()){
    vb = op(b);
  } else {
    vb = ump[b];
  }

  if (operation == "union") {
    set_union(va.begin(), va.end(), vb.begin(), vb.end(), back_inserter(ret));
  } else if (operation == "intersection") {
    set_intersection(va.begin(), va.end(), vb.begin(), vb.end(), back_inserter(ret));
  } else {
    set_difference(va.begin(), va.end(), vb.begin(), vb.end(), back_inserter(ret));
  }
  return ret;
}

int main() {
  while (cin >> s) {
    if (s == "group") {
      cin >> x;
      cin >> n;
      ump[x] = vector<string>();
      rep(i, 0, n) {
        cin >> name;
        ump[x].push_back(name);
      }
      sort(ump[x].begin(), ump[x].end());
    } else {
      if (ump.find(s) == ump.end()) {
        out = op(s);
      } else {
        out = ump[s];
      }
      rep(i, 0, out.size()) {
        cout << out[i] << " ";
      }
      cout << '\n';
    }
  }
}
