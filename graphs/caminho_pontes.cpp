#include <bits/stdc++.h>
using namespace std; 
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using ii = pair<int,int>;


void solve(){
  int n, m; cin >> n >> m;
  n += 2;
  vector<vector<ii>> AL(n);
  for(int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    AL[u].emplace_back(v, w);
    AL[v].emplace_back(u, w);
  }
  vector<optional<int>> dist(n);
  dist[0] = 0;
  set<ii> pq;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    auto [d, u] = *pq.begin();
    pq.erase(pq.begin());

    for (auto &[v,w]: AL[u]) {
      if (!dist[u].has_value()) continue;
      if (dist[v].has_value() && dist[u].value() + w >= dist[v].value()) continue;
      if (dist[v].has_value()) pq.erase(pq.find({dist[v].value(), v}));
      dist[v] = dist[u].value() + w;
      pq.emplace(dist[v].value(), v);
    }
  }
  cout << dist[n-1].value() << '\n';
}

int main(){
  fast_io;
  //int t; cin >> t; while(t--)
  solve();

  return 0;
}

