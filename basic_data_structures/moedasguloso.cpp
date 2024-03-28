// source: Neps Academy
// Topic: Greedy Algorithm

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back

void solve(){
  vector<int>s = {1, 5, 10, 25, 50, 100};
  int v; cin >> v;
  int ans = 0;
  for(int i = s.size()-1; i >= 0; i--) {
    while(v >= s[i]) {
      v -= s[i];
      ans++;
    }
  }
  cout << ans << endl;
}

int main(){
    fast_io;
    //ll t; cin >> t; while(t--)
    solve();

    return 0;
}
