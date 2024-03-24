/*
  source: OBI 2007 (first phase)
  topic: matrix
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
  vector<vector<int>>v(n, vector<int>(n));
  int suml = 0, sumd = 0, sumc = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> v[i][j];
    }
  }

  int rl, rc;
  for(int i = 0; i< n; i++){
    for(int j = 0; j < n; j++){
      suml += v[i][j];
      sumc += v[j][i];
    }
    if(i == 0 || (sumc == rc && rl == suml)){
      rl = suml; rc = sumc;
      suml = 0; sumc = 0;
    } else{
      cout << -1 << endl;
      return;
    }
  }
  int sumdb = 0;
  for(int i = 0; i < n; i++){
    sumd += v[i][i];
    sumdb += v[i][n-1-i];
  }
  cout << (sumd == sumdb && sumdb == rl? rl : -1) << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

