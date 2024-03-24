#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

void solve(){
  vector<int>a(3);
  for(auto &x:a) cin >> x;
  int suma = a[1] * 2 + a[2] * 2 * 2;
  int sumb = a[0] * 2 + a[2] * 2;
  int sumc = a[0] * 2 * 2 + a[1] *2;
  suma = min(suma, sumb);
  suma = min(suma, sumc);
  cout << suma << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

