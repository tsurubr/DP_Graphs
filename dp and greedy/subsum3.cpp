#include <iostream>
#include <optional>
#include <vector>
#include <utility>
#include <map>
#include <functional>
#include <set>

using namespace std;

using it = vector<int>::iterator;

map<int, int> all_sums(it b, it e) {
    map<int, int> sums;

    // o último elemento usado para compor s é b[k-1]
    auto recur = [&](auto&& recur, int s, it i, int k) -> void {
        if (i == e) 
            sums[s] = sums.find(s) == sums.end() ? k : min(sums[s], k);
        else {
            recur(recur, s, i+1, k);
            recur(recur, s + *i, i+1, distance(b, i+1)); // formou s usando *i, ou seja, no intervalo [b:i+1)
        }
    };
    recur(recur, 0, b, 0);
    return sums;
}


 
class subset_sum {
private:
    map<int, int> sums1;
    map<int, int> sums2;
    vector<int> elems;

    using opii = optional<pair<int, int>>;

    opii find_pair(int s) { 
        auto b1 = sums1.begin(), e1 = sums1.end();
        auto b2 = sums2.rbegin(), e2 = sums2.rend();
        while (b1 != e1 && b2 != e2) {
            int x = (*b1).first;
            int y = (*b2).first;
            int v = x + y;
            if (v == s) return opii {{x, y}};
            if (v < s) ++b1;
            else ++b2;
        }
        return {};
    };

    // sums.find(s) != sums.end()
    vector<int> build(int s, map<int, int> &sums, it b) {
        vector<int> rs;
        while (s != 0) {
            int k = sums[s];
            rs.push_back(b[k-1]);   // b[k-1] é o mesmo que *(b+k-1)
            s -= b[k-1];
        }
        return rs;
    } 

public:
    subset_sum(it b, it e) {
        copy(b, e, back_inserter(elems));
        auto d = distance(b, e) / 2;
        sums1 = all_sums(b, b+d);
        sums2 = all_sums(b+d, e);
    }

    optional<vector<int>> search(int s) {
        auto op = find_pair(s);
        if (!op.has_value()) return {};
        auto [x, y] = *op;
        auto d = distance(elems.begin(), elems.end()) / 2;
        auto xs = build(x, sums1, elems.begin());
        reverse(xs.begin(), xs.end());
        auto ys = build(y, sums2, elems.begin() + d);
        copy(ys.rbegin(), ys.rend(), back_inserter(xs));
        return xs;
    }
}; 


int main() {
    vector<int> v {1, 10, 9, 20, 40, 5, 100, 7};
    auto sums = all_sums(v.begin(), v.end());
    subset_sum ss(v.begin(), v.end());
    for (auto [s, k]: sums) { 
        auto xs = *(ss.search(s));
        cout << s << ": ";
        for (int x : xs) 
            cout << x << ' ';
        cout << '\n';
    }
}