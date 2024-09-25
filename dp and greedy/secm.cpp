#include <iostream>
#include <vector>
#include <utility>
#include <optional>
#include <iterator>

using namespace std;

using it = vector<int>::iterator;

int secm(it b, it e) {
    // devolve o comp da maior secm de *[b:e) que cujos elementos são maiores que op
    auto recur = [](auto&& recur, it b, it e, optional<int> op) {
        if (b == e) return 0;
        int m2 = recur(recur, b+1, e, op);
        if (op.has_value()) {
            if (op.value() < *b) {
                int m1 = 1 + recur(recur, b+1, e, *b);
                return max(m1, m2);
            }
            return m2;
        }
        int m1 = 1 + recur(recur, b+1, e, *b); 
        return max(m1, m2);
    };

    return recur(recur, b, e, {});
}

void pr_vec(vector<int>& v) {
    for (int x: v)
        cout << x << ' ';
    cout << endl;
}

void sec_print(it b, it e) {
    vector<int> ss;
    ss.reserve(distance(b, e));
    auto recur = [&](auto&& recur, it b, it e) -> void {
        if (b == e) {
            pr_vec(ss);
            return;
        }
        recur(recur, b+1, e);
        if (ss.size() > 0) {
            if (ss[ss.size()-1] < *b) {
                ss.push_back(*b); 
                recur(recur, b+1, e);
                ss.pop_back();
            }
            return;
        }
        ss.push_back(*b);
        recur(recur, b+1, e);
        ss.pop_back();
    };

    recur(recur, b, e);
}

vector<int> secm_witness(it b, it e) {
    vector<int> rs;
    rs.reserve(distance(b, e));
    vector<int> ss;
    ss.reserve(distance(b, e));

    auto recur = [&](auto&& recur, it b, it e) -> void {
        if (b == e) {
            if (ss.size() > rs.size()) rs = ss;
            return;
        }
        recur(recur, b+1, e);
        if (ss.size() > 0) {
            if (ss[ss.size()-1] < *b) {
                ss.push_back(*b); 
                recur(recur, b+1, e);
                ss.pop_back();
            }
            return;
        }
        ss.push_back(*b);
        recur(recur, b+1, e);
        ss.pop_back();
    };

    recur(recur, b, e);
    return rs;
}


int main() {
    vector<int> v {5, 1, 2, 1, 4, 2, 7, 2, 9, 11, 1, 12, 3};
    auto r = secm_witness(v.begin(), v.end());
    pr_vec(r);
}
