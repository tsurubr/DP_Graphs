#include <bits/stdc++.h>
using namespace std; 
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using vi = vector<int>;

void bfs(int s, vector<vi>& graph, vector<optional<int>>& dist) {
  dist[s] = 0;
  queue<int> q; q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto& v: graph[u]) {
      if (dist[v].has_value()) continue;
      dist[v] = dist[u].value() + 1;
      q.push(v);
    }
  }
}

void solve(){
  int n; cin >> n;
  vector<vector<int>>graph(n+1);
  for (int i = 0; i < n; i++) {
    int u, v; cin >> u >> v;
    graph[v].push_back(u);
  }
  vector<optional<int>> dist(n+1);
  bfs(0, graph, dist);
  bool ok = true;

  vector<pair<int, int>> vp(n+1);
  for(int i = 0; i <= n; i++)
    vp[i] = {dist[i].value(), i};


  sort(vp.begin(), vp.end());
  int j = 0;
  for (int i = 1; i <= n; i++, j++) {
    if (vp[i].first != vp[j].first) continue;
    if (graph[vp[j].second].size() != graph[vp[i].second].size())
      ok = false; break;
  }
  cout << (ok? "bem" : "mal") << '\n';
}

int main(){
  fast_io;
  //ll t; cin >> t; while(t--)
  solve();

  return 0;
}

