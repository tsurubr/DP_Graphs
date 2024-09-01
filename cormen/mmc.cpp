#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void mmc(vector<vector<optional<int>>>& m, vector<int>&p, int n) {
    int q;
    auto recur = [&](auto&& recur, int i,int j,vector<int>& p) -> int {
        if (m[i][j]) return *m[i][j];
        if (i == j) return *(m[i][j] = 0);
        for (int k = i; k < j; k++) {
            q = recur(recur, i, k, p) + recur(recur, k+1, j, p) + p[i-1] * p[k] * p[j];
            if (!m[i][j]) m[i][j] = q; 
            else if (q < m[i][j]) m[i][j] = q;
        }
        return *m[i][j];
    };
    recur(recur, 1, n-1, p);
}

void solve() {
    vector<int> p {30, 35, 15, 5, 10, 20, 25};
    int n = p.size();
    vector<vector<optional<int>>> m(n, vector<optional<int>>(n));
    mmc(m, p, n);
    cout << *m[1][5] << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*   Pikachu
*/    
