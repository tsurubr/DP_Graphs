#include <bits/stdc++.h>
using namespace std;

string lcs (string a, string b, int n, int m) {
    vector<vector<optional<int>>> dp(n+1, vector<optional<int>>(m+1));
    auto recur = [&] (auto&& recur, int i, int j) -> int {
        if (dp[i][j]) return *dp[i][j];
        if (i == 0 || j == 0) return 0;
        if (a[i-1] == b[j-1]) dp[i][j] = recur(recur, i-1, j-1) + 1;
        else dp[i][j] = max(recur(recur, i-1, j), recur(recur, i, j-1));
        return *dp[i][j];
    };
    int ans = recur(recur, n, m);
    string z;
    auto build = [&] (auto&& build, int n, int m) {
        if (n == 0 || m == 0) return;
        if (a[n-1] == b[m-1]) {
            z.push_back(a[n-1]);
            build(build, n-1, m-1);
        }
        else if (dp[n-1][m] >= dp[n][m-1]) build(build, n-1, m);
        else build(build, n, m-1);
   
    };
    build(build, n, m);
    reverse(z.begin(), z.end());
    return z;
}

int lcsi (string a, string b, int n, int m) {
    vector<vector<int>> ans(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) ans[i][j] = ans[i-1][j-1] + 1;
            else ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
        }
    }
    return ans[n][m];
}

void solve() {
    string a, b, z; cin >> a >> b;
    int n = a.size(), m = b.size();
    z = lcs(a, b, n, m);
    cout << lcsi(a, b, n, m) << '\n';
    cout << z << '\n';
    cout << z.size() << '\n';
}

int main() {
    solve();
    return 0;
}
