#include "bits/stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define nl "\n"

typedef long long ll;

const double EPS = 1e-9;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  //
  bool operator == (point other) const {
   return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));
  }

  bool operator <(const point &p) const {
   return x < p.x || (abs(x-p.x) < EPS && y < p.y); 
  }
};

// returns the area of polygon P
double area(const vector<point> &P) {
  double ans = 0.0;
  for (int i = 0; i < (int)P.size()-1; ++i)      // Shoelace formula
    ans += (P[i].x*P[i+1].y - P[i+1].x*P[i].y);
  return fabs(ans)/2.0;                          // only do / 2.0 here
}

int main() {
  auto comp = [](const pair<double, vector<int>>& v1, const pair<double, vector<int>>& v2) {
    if (v1.first != v2.first) {
      return v1.first > v2.first;
    } else {
      return (v1.second)[0] > (v2.second)[0];
    }
  };
  priority_queue<pair<double, vector<int>>, 
    vector<pair<double, vector<int>>>, 
    decltype(comp)> pq(comp);
  int n, m; cin >> n >> m;
  vector<point> p;
  double x, y;
  rep(i,0,n+1) {
    cin >> x >> y;
    p.push_back(point{x, y});
  }

  double a;
  vector<point> v(4);
  //printf("a          p1   p2  p3\n");
  rep(i,0,n-1) {
    v[0] = p[i];
    v[1] = p[i+1];
    v[2] = p[i+2];
    v[3] = p[i];
    a = area(v);
    pq.push({a, {i, i+1, i+2}});
    //printf("%08.2f    %d    %d    %d\n", a, i, i+1, i+2);
  }

  vector<int> out(n+1);

  int b;
  vector<int> c;
  rep(z,m,n) {
    // get element
    while (true) {
      auto [x, y] = pq.top();
      pq.pop();
      bool can = true;
      rep(i,0,3) {
        if (out[y[i]]) {
          can = false;
        }
      }
      if (can) {
        b = x;
        c = y;
        break;
      }
    }
    cout << c[1] << nl;
    out[c[1]] = 1;
    int i = c[0]-1;
    if (i >= 0) {
      while (out[i]) --i;
      if (i >= 0) {
        v[0] = p[i];
        v[1] = p[c[0]];
        v[2] = p[c[2]];
        v[3] = p[i];
        a = area(v);
        // printf("%08.2f    %d    %d    %d\n", a, i, c[0], c[2]);
        pq.push({a, {i, c[0], c[2]}});
      }
    }
    i = c[2]+1;
    if (i < n+1) {
      while (out[i]) ++i;
      if (i < n+1) {
        v[0] = p[c[0]];
        v[1] = p[c[2]];
        v[2] = p[i];
        v[3] = p[c[0]];
        a = area(v);
        // printf("%08.2f    %d    %d    %d\n", a, c[0], c[2], i);
        pq.push({a, {c[0], c[2], i}});
      }
    }
  }
}
