#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
using graph = vector<vector<ll>>;
void solve(){
    const ll INF = 1e18;
    ll n, m, q; cin >> n >> m >> q;
    graph g(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u][v] = min(w, g[u][v]);
        g[v][u] = min(w, g[v][u]);
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        cout << (g[a][b] == INF? -1 : g[a][b]) << '\n';
    }
}

int main(){
    fastio; 
    solve();
    return 0;
}

