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
  vector<int>a(n);
  int sum = 0, ans = 0;
  for(int i = 0; i < n; i++){
    int num; cin >> num;
    sum += num;
    if(sum >= 1e6){
      cout << i + 1 << endl;
      break;
    }
  }
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

