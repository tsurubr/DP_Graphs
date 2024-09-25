#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int mod = 1e9 + 7;
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1;

    for (int i  = 1; i <= n; i++) {
        for (int j = 1; j <= i && j <=6; j++) {
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    solve();
    return 0;
}