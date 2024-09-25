#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void solve() {
    int n, x; cin >> n >> x;
    vector<int> v(n), memo(x+1, -1);
    for (auto& e : v) cin >> e;
    memo[0] = 0;
    auto dp = [&](auto&& dp, int i) -> int {
        if (i < 0) return 1e9;
        if (memo[i] != -1) return memo[i];
        int q = 1e9;
        for (auto& e: v) {
            q = min(q, dp(dp, i - e) + 1);
        }
        return memo[i] = q;
    };
    int ans = dp(dp, x);
    cout << (ans < 1e9? ans : -1) << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*   Pikachu
*/    