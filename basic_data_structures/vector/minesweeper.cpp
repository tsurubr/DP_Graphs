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
  vector<int>a(n), ans(n, 0);
  for(auto &x:a) cin >> x;
  ans[0] = a[0] + a[1];
  ans[n-1] = a[n-1] + a[n-2];
  for(int i = 1; i < n-1; i++){
    ans[i] = a[i-1] + a[i+1] + a[i]; 
  }
  for(auto x:ans) cout << x << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

