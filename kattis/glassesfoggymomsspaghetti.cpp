#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"

typedef long long ll;

const double EPS = 1e-9;

struct point {
  double x, y;             // only used if more precision is needed
  point() { x = y = 0.0; } // default constructor
  point(double _x, double _y) : x(_x), y(_y) {} // user-defined
  //
  bool operator==(point other) const {
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
  }

  bool operator<(const point &p) const {
    return x < p.x || (abs(x - p.x) < EPS && y < p.y);
  }
};

// returns the area of polygon P
double area(const vector<point> &P) {
  double ans = 0.0;
  for (int i = 0; i < (int)P.size() - 1; ++i) // Shoelace formula
    ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
  return fabs(ans) / 2.0; // only do / 2.0 here
}

int main() {
  double ab, a, b, alpha, beta, gamma;
  double d, x, y, h;
  double ans;
  cin >> d >> x >> y >> h;
  alpha = atan(x / y);
  beta = atan(2 * x / (2 * y - h));
  gamma = M_PI / 2 + alpha - beta;
  a = atan2(2 * y + h, 2 * x) - atan2(y, x);
  b = atan2(y, x) - atan2(2 * y - h, 2 * x);
  ab = atan2(2 * y + h, 2 * x) - atan2(2 * y - h, 2 * x);
  ans = d * sin(b) / sin(gamma) + d * sin(a) / sin(M_PI - ab - gamma);
  cout << fabs(ans);
}
