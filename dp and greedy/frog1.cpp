#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
    int n; cin >> n;
    vector<int>v(n);
    for(auto &x: v) cin >> x;
    vector<int> memo(n, 1e9);
    auto dp = [&](auto&& dp, int i) -> int{
        if(memo[i] != 1e9) return memo[i];
        if (i == 0) return 0;
        if (i == 1) return abs(v[1] - v[0]);
        return memo[i] = min((dp(dp, i-1) + abs(v[i-1] - v[i])), (dp(dp, i-2) + abs(v[i-2] - v[i])));
    };
    cout << dp(dp, n-1) << '\n';
}

int main(){
    fastio; 
  //int t; cin>>t; while(t--)
    solve();

    return 0;
}

