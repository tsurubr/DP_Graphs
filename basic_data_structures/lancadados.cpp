/*
  source: Neps Academy
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
  int n; cin >> n;
  map<int, int> cnt;
  vector<int> v(n);

  for(auto &x : v) cin >> x;
  for(auto &y : v) {
    cnt[y]++;
  }
  int maxocrr = 0;
  for(auto &par: cnt) {
    if(par.second > maxocrr) {
      maxocrr = par.second;
    }
  }
  for(const auto x: cnt) {
    if (x.second == maxocrr) cout << x.first << " ";
  }
  cout << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

