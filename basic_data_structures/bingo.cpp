/*
  source: OBI 2020 (first phase)
  topic: map
*/
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define pb push_back

void solve(){
  int n, k, u;
  cin >> n >> k >> u;
  
  unordered_map<int, vector<int>> bingo;
  vector<int> winners, count(n, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k; j++) {
      int x; cin >> x;
      bingo[x].pb(i);
    }
  }
  
  for(int i = 0; i < u && winners.empty(); i++) {
    int num; cin >> num;
    if (bingo.find(num) != bingo.end()) {
      for(auto &x: bingo[num]) {
        if(++count[x] == k) {
          winners.pb(x);
        }
      }
    }
  }
  sort(winners.begin(), winners.end());

  for(auto &x: winners) cout << x+1 << ' ';
  cout << endl;
}

int main(){
    fast_io;
    solve();
    return 0;
}
