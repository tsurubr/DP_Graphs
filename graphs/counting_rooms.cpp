#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using graph = vector<vector<char>>;


const vector<int> nx {0, 1, 0, -1}, ny {1, 0, -1, 0};
void dfs_count(graph& g, int x, int y, vector<vector<bool>>& visited) {
    int n = g.size();
    int m = g[0].size();
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int dx = x + nx[i], dy = y + ny[i]; 
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && g[dx][dy] == '.' && !visited[dx][dy]){
            dfs_count(g, dx, dy, visited);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    graph g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j];
        }
    }
    int ans = 0;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(g[i][j] == '.' && !visited[i][j]){
                dfs_count(g, i, j, visited);
                ans++;
            }      
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}

