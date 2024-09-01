#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int optimal_bst(vector<int>& e, int n) {
    vector<int> s(n+1, 0);  // Vetor de soma prefixa
    vector<vector<int>> c(n, vector<int>(n, 0));  // Matriz de custos

    // Cálculo da soma prefixa
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + e[i-1];
    }

    // Cálculo da matriz de custo
    for (int l = 1; l <= n; l++) {  // l é o comprimento da subárvore
        for (int i = 0; i <= n-l; i++) {
            int j = i + l - 1;
            c[i][j] = (i+1 <= j) ? c[i+1][j] : 0;
            for (int k = i; k <= j; k++) {
                int temp = (k > i ? c[i][k-1] : 0) + (k < j ? c[k+1][j] : 0);
                if (k == i || temp < c[i][j]) {
                    c[i][j] = temp;
                }
            }
            c[i][j] += s[j+1] - s[i];
        }
    }

    // Devolver o custo mínimo
    return c[0][n-1];
}

void solve() {
    int n;
    cin >> n;
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    int ans = optimal_bst(e, n);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
