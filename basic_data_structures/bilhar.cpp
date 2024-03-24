#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

void solve(){
  int c; cin >> c;
  vector<int> a(c);
  for(auto &x: a) cin >> x;
  int ans = 0;
  set<int>estoque;
  for(int i = 0; i < c; i++){
    if(estoque.find(a[i]) == estoque.end()){
      ans+=2;
      estoque.insert(a[i]);
    } else{
      estoque.erase(a[i]);
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
