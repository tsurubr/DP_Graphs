// Topic: DFS
// Source: OBI 2011 (2nd phase)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<long long>
#define vi vector<int>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back

using namespace std;

using graph = vector<vi>;

//vector<optional<int>> 
void dfsi(graph &g, int s, vector<bool> &visited) {
    stack<tuple<int, vector<int>::iterator, vector<int>::iterator>> st;
    st.push({s, g[s].begin(), g[s].end()});
    //vector<optional<int>> pred(g.size());
    //pred[s] = s;
    visited[s] = true; 
    while (!st.empty()) {
        auto &[u, b, e] = st.top();
        if (b == e) {
            st.pop();
            continue;
        }
        int t = *b++;
        if (!visited[t]) {
            //pred[t] = u;
            st.push({t, g[t].begin(), g[t].end()});
            visited[t] = true;
        }
    }
    //return pred;
}

int main() {int n, m;   
  cin >> n >> m;
  graph g(n); 
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> visited(n, false);  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      ans++;
      dfsi(g,i,visited);
    }
  }
  cout << ans << endl;
  
  return 0;
}
