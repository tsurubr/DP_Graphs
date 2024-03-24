/*
  source: OBI 2010 (second phase)
  topic: union find
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define pb push_back

const int MAXN = 1e5;
int parent[MAXN], tam[MAXN];

int find(int value){
  if(parent[value] == value)
    return value;
  return parent[value] = find(parent[value]);
}

void merge(int i, int j){
  i = find(i); j = find(j);
  if(i == j) return;
  if (tam[i] >= tam[j]){
    parent[j] = i;
    tam[i] += tam[j];
  } else {
    parent[i] = j;
    tam[j] += tam[i];
  }
}

void solve(){
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; i++){
    parent[i] = i;
    tam[i] = 1;
  }

  for(int i = 0; i < k; i++){
    char q; cin >> q;
    int a, b; cin >> a >> b;
    if(q == 'C') {
      if(find(a) == find(b)) cout << "S" << endl;
      else cout << "N" << endl;
    } else {
      merge(a,b);
    }
  }
}

int main(){
  fast_io; 
  //int t; cin>>t; while(t--)
  solve();

  return 0;
}

