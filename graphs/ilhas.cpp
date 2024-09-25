#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void solve() {
    int n, m, s;
    cin >> n >> m;
    vector<tuple<int, int, int>> g;
    vector<int> dist(n + 1, 1e9);
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        g.push_back({u, v, p});
        g.push_back({v, u, p});
    }

    cin >> s;
    dist[s] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto& e: g) {
            int a, b, w; tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }

    int mini = 1e9, maxi = -1;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (dist[i] != 1e9) {
            mini = min(mini, dist[i]);
            maxi = max(maxi, dist[i]);
        }
    }
    cout << (maxi - mini) << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}
