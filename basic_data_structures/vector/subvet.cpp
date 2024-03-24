#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

void solve(){
  int n = 10; int mini = 1e5;
  vector<int>v(n);
  vector<int>ocr;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    v[i] = a;
    if(v[i] <= mini){
      if(v[i] != mini) ocr.clear();
      mini = v[i];
      ocr.push_back(i);
    }
  }
  cout << "Menor: " << mini << endl << "Ocorrencias: ";
  for(auto x: ocr) cout << x << ' '; 
  cout << endl;
  for(int i = 0; i < n;i++){
    cout << (v[i] == mini? -1 : v[i]) << ' ';
  }
  cout << endl;
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

