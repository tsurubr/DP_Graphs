#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

void solve(){
  ll ans = 1;
  int n; cin >> n;
  vector<int>a(n);
  for(auto &x:a) cin >> x;
  ans = max(a[n-1] * a[n-2] * a[n-3], a[0] * a[1] * a[n-1]);
  cout << ans << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

