/*
  source: OBI 2015 (second phase)
  topic: pair
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
  double m = ceil(n/2.0);
  vector<pair<int,int>>a;
  for(int i = 0; i < 2; i++){
    int x, y; cin >> x >> y; 
    a.pb(make_pair(x, y));
  }
  for(auto x:a) cout << ceil(x.first/m) << ' ' << ceil(x.second/m) << endl;
  if(ceil(a[0].first/m) == ceil(a[1].first/m) && ceil(a[0].second/m) == ceil(a[1].second/m))
    cout << 'N' << endl;
  else
    cout << 'S' << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}
