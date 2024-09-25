#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
using vi = vector<long long>;
void solve() {
    ll n, h; cin >> n >> h;
    vector<vi> tree(n, vi(h)), dp(n, vi(h, 0));
    for (ll i = 0; i < n; i++) 
        for (ll j = 0; j < h; j++) 
            cin >> tree[i][j];
 
    auto step = [&](auto&& step, ll i, ll j) -> ll {
        if (j == h || i == n || i < 0) return 0;
        if (dp[i][j] > 0) return dp[i][j];
        ll q = 0;
        if (i == 0 || i == n-1) q = max(step(step, i, j+1), (i == 0? step(step, i+1, j+1) : step(step, i-1, j+1)));
        else q = max(step(step, i, j+1), max(step(step, i+1, j+1), step(step, i-1, j+1)));
        return dp[i][j] = q + tree[i][j];
    };
    ll ans = step(step, 0, 0);
    for (ll i = 1; i < n; i++) {
        ans = max(ans, step(step, i, 0));
    }
    cout << ans << '\n';
}
 
int main() {
    fastio;
    solve();
    return 0;
}
