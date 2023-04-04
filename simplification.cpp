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
  priority_queue<pair<double, vector<int>>> pq;
  int n, m; cin >> n >> m;
  vector<point> p;
  double x, y;
  rep(i,0,n+1) {
    cin >> x >> y;
    p.push_back(point{x, y});
  }

  double a;
  vector<point> v(3);
  rep(i,0,n-1) {
    v[0] = p[i];
    v[1] = p[i+1];
    v[2] = p[i+2];
    a = area(v);
    pq.push({a, {i, i+1, i+2}});
  }

  vector<int> out(n+1);

  int left = n+1;
  while (left > m) {
    // get element
  }
}
