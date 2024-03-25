#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define endl "\n"

// based on A&DS course lectured by Pavel Mavrin

vector<int> merge(vector <int> a, vector <int> b) {
  int n = a.size();
  int m = b.size();
  int i = 0, j = 0, k = 0;
  vector <int> c(n+m);
  while(i < n || j < m) {
    if(j == m || i < n && a[i] < b[j]) c[k++] = a[i++];
    else c[k++] = b[j++];
  }
  return c;
}

vector<int> merge_sort(vector<int> a) {
  int n = a.size();
  if(n < 2) return a;
  int mid = n/2;
  vector<int>b(a.begin(), a.begin() + mid);
  vector<int> c(a.begin() + mid, a.end());
  b = merge_sort(b);
  c = merge_sort(c);
  return merge(b,c);
}

void solve(){
  vector<int>v = {15, 0, 10, 3, 7, 2, 1};
  v = merge_sort(v);
  for(auto &x :v) cout << x << ' ';
  cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //ll t; cin >> t; while(t--)
    solve();

    return 0;
}

