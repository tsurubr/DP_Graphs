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
  vector<int>zero;
  zero.pb(-1e9);
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x == 0) zero.pb(i);
  }
  zero.pb(1e9);
  for(int i = 0, j = 0; i < n; i++) {
    if(zero[j+1] == i) j++;
    cout << min(9, min(abs(zero[j] - i), abs(zero[j+1]-i))) << ' ';
  }
  cout << endl;
} 

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

