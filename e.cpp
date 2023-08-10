#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define nl "\n"
typedef long long ll;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<int, int>> mat(26), nomat(26);
        int swp = 0, ct = 0;
        if (s.size() % 2) {
            cout << -1 << nl;
            continue;
        }
        rep(i, 0, 26) {
            mat[i] = {0, i};
            nomat[i] = {0, i};
        }
        rep(i, 0, s.size() / 2) {
            if (s[i] == s[n - 1 - i]) {
                mat[s[i] - 'a'].first++;
                ++swp;
            } else {
                nomat[s[i] - 'a'].first++;
                nomat[s[n - 1 - i] - 'a'].first++;
            }
        }
        ct = swp;
        sort(mat.rbegin(), mat.rend());
        cerr << nomat[mat[0].second].first << " " << mat[0].first << nl;
        while (true) {
            sort(mat.rbegin(), mat.rend());
            if (mat[0].first == 0) {
                break;
            }
            if (mat[1].first > 0) {
                mat[0].first--;
                mat[1].first--;
                swp--;
            } else {
                break;
            }
        }
        cerr << nomat[mat[0].second].first << " " << mat[0].first << nl;
        if (s.size() / 2 - nomat[mat[0].second].first - ct >= mat[0].first) {
            cout << swp << nl;
        } else {
            cout << -1 << nl;
        }
        cerr << nl;
    }
}
