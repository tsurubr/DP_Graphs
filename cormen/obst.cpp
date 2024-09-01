#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int obst (vector<int>& p, int n) {
    vector<int> s(n+1, 0);
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 1; i <= n; i++){
        s[i] = s[i-1] + p[i-1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i + l - 1;
            if (i < j) c[i][j] = c[i+1][j];
            for (int r = i; r <= j; r++) {
                c[i][j] = min(c[i][j], (r > i? c[i][r-1] : 0) + (r<j? c[r+1][j]:0));
            }
            c[i][j] += s[j+1] - s[i];
        }
    }
    return c[0][n-1];
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x: v) cin >> x;
    int ans = obst(v, n);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}

/*   
*    /\_/\
*   (= ._.)
*   / >  \>
*   Pikachu
*/    