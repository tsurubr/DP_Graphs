/*
  source: OBI 2016 (first phase)
  topic: map
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

void solve(){
  int n, d; cin >> n >> d;
  vector<int>a(n);
  for(auto &x:a) cin >> x;
  int ans = 0;
  int r = 0, sum = 0;
  // subsequencia
  for(int l = 0; l < n; l++){
    while(sum < d && r < n){
      sum += a[r++];
    }
    if(sum == d) ans++;
    sum -= a[l];
  }
  cout << ans << ' ';
  // extremos
  map<int, int>s_cnt;
  vector<int> pf(n), sf(n);
  pf[0] = a[0]; sf[n-1] = a[n-1];
  for(int i = 1; i < n; i++){
    pf[i] = pf[i-1] + a[i];
    sf[n-i-1] = sf[n-i] + a[n-i-1];
  }

  for(int i = n-2; i >= 0; i--){
    s_cnt[sf[i+1]]++;
    if(pf[i] <= d){
      ans += s_cnt[d-pf[i]];
    }
  }
  cout << ans << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

