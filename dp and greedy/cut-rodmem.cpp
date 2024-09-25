#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int memo_cutrod(const vector<int>& p, int n, vector<optional<int>>& r) {
    if (n == 0) return 0; 
    if (r[n]) return *r[n];
    int q = -1e9; // infinity
    for (int i = 1; i <= n; i++)
        q =  max(q, p[i] + memo_cutrod(p, n-i, r));
    return r[n] = q;
}

int bottom_up(const vector<int>& p, int n, vector<optional<int>>& r) {
    if (n == 0) return 0;
    r[0] = 0;
    for (int i = 1; i <= n; i++) {
        int q = -1e9; // infinity
        for (int j = i; j <= n; j++) {
            q = max(q, p[i] + *r[i]);
            r[j] = q;
        }
        r[i] = q;
    }
    return *r[n];
}

void solve() {
    vector<int> p {0, 5, 7, 10};
    vector<optional<int>> r(p.size());
    r[0] = 0;
    int ans = bottom_up(p, 3, r);
    cout << ans << '\n';
}

int main() {
    fastio;
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
/*   /\_/\
*   (= ._.)
*   / >  \>
*   Pikachu
*/

