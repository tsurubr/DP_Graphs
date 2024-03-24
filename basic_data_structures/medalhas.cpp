#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

void solve(){
  vector<pair<int, int>>a(3);
  for(int i = 0; i < 3; i++){
    int x; cin >> x;
    a[i] = make_pair(x, i);
  }
  sort(a.begin(), a.end());
  for(auto x: a){
    cout << x.second + 1 << endl;
  }
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

