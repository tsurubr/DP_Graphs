#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
    int n; cin >> n;
    vector<int>v(3);
    for (auto&x: v) cin >> x;
    vector<optional<int>> dp(n+1, nullopt);
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = v[i]; j <= n; j++) {
            if (!dp[j-v[i]]) continue;
            dp[j] = (dp[j]? max(*dp[j], *dp[j-v[i]] + 1) : *dp[j-v[i]] + 1);
        }
    }
    cout << *dp[n] << '\n';
}

int main(){
    fastio; 
  //int t; cin>>t; while(t--)
    solve();

    return 0;
}

