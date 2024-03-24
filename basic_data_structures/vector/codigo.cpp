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
  vector<int>v(n);
  for(auto &x:v) cin >> x;
  int ans = 0;
  for(int i = 0; i < n-2; i++){
    if(v[i] == 1) {
      if(v[i+1] == 0) {
        if(v[i+2] == 0) ans++;
      }
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

