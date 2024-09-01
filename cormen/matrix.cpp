#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using matrix = vector<vector<optional<int>>>;

inline int minq(optional<int>&op, int q) {
    if (!op) return q;
    return min(*op, q);
}

matrix mat_chain(vector<int>& p, int n, vector<vector<int>> s) {
    matrix m(n, vector<optional<int>>(n, nullopt)); 
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; ++l) { 
        for (int i = 1; i <= n - l; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                int q = *m[i][k] + *m[k + 1][j] + p[i-1] * p[k] * p[j];
                m[i][j] = minq(m[i][j], q);
                s[i][j] = (m[i][j] == q? k : s[i][j]);
            }
        }
    }
    return m;
} 

void solve() {
    vector<int> p {30, 35, 15, 5, 10, 20, 25};
    int n = p.size();
    vector<vector<int>> s(n, vector<int>(n));
    matrix m = mat_chain(p, n, s);
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

