#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
void solve() {
    ll n, x, mod = 1e9 + 7; cin >> n >> x;
    vector<ll> v(n), dp(x+1, 0);
    for (auto& e: v) cin >> e;
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for(auto& e: v) {
            if (e <= i) dp[i] = (dp[i] + dp[i-e]) % mod;
        }
    }
    cout << dp[x] << '\n'; 
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