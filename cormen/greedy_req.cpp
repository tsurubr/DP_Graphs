#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using vii = vector<pair<int, int>>;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

vii greedy(vii& r) {
    vii ans;
    sort(r.begin(), r.end(), comp);
    ans.push_back(r[0]);
    int cur = r[0].second;
    for (auto& t: r) { // verificando todos os elementos em R
        if (t.first >= cur) { // ignorando os conflitos
            ans.push_back(t);
            cur = t.second;
        }
    }
    return ans;
}

int main() {
    fastio;
    vii req {{1,2}, {5,6}, {5, 10}, {6, 9}, {6, 8}};
    vii ans = greedy(req);
    cout << ans.size() << '\n';
    for (auto& x: ans) {
        cout << "começo: " << x.first << " final: " << x.second << '\n';
    }

    return 0;
}

/*  
*    /\_/\
*   (= ._.)
*   / >  \>
*   Pikachu
*/

