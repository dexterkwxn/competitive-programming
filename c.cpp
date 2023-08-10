#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"
typedef long long ll;

int main() {
    int m, s;
    cin >> m >> s;
    if (s == 0) {
        cout << "-1 -1";
        return 0;
    }  
    vector<int> l(m), h(m);

    l[0] = 1;
    int ns = s-1;
    for (int i = m-1; i >= 0; --i) {
        if (ns == 0) break;
        while (l[i] < 9) {
            ++l[i];
            --ns;
            if (ns == 0) break;
        }
    }

    h[0] = 1;
    ns = s-1;
    rep(i,0,m) {
        if (ns == 0) break;
        while (h[i] < 9) {
            ++h[i];
            --ns;
            if (ns == 0) break;
        }
    }

    if (ns != 0) {
        cout << "-1 -1";
        return 0;
    }  

    string r = "", t = "";
    rep(i,0,m) {
        r += to_string(l[i]);
        t += to_string(h[i]);
    }
    cout << r << " " << t;
}
