/*
  source: Neps Academy
  topic: set
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
  int a, b; cin >> a >> b;
  set<int>x, y, mn, gt;
  for(int i = 0; i < a; i++){
    int n; cin >> n;
    x.insert(n);
  }
  int ans = 0;
  for(int i = 0; i < b; i++){
    int n; cin >> n;
    y.insert(n);
  }
  mn = (x.size() < y.size() ? x : y);
  gt = (x.size () >= y.size() ? x : y);

  auto ptr = mn.begin();
  for(int i = 0; i < mn.size(); i++){
    if(gt.find(*ptr) == gt.end()){
      ans++;
      gt.insert(*ptr);
    }
    ptr++;
  }
  cout << ans << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

