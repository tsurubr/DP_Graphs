#include <bits/stdc++.h>
using namespace std;

int weighted_interval(vector<int>& v,vector<optional<int>>& p) {
  int n = v.size();
  vector<optional<int>> dp(n, nullopt);
  dp[0] = v[0];
  // dp[k] é uma solução otima envolvendo o prefixo {0...k}
  auto opt = [&](auto&& opt, optional<int> j) -> int {
    if (!j) return 0;
    if (dp[*j]) return *(dp[*j]);
    return *dp[*j] = max(v[*j] + opt(opt, p[*j]), opt(opt, *j-1));
  };
  int ans = opt(opt, n-1);

  auto print = [&] (auto&& print, optional<int> j) -> void {
    if (!j) {
      cout << '\n';
      return;
    }
    if (*j == 0 || p[*j] && v[*j] + *dp[*p[*j]] >= *dp[*j-1]) {
      cout << *j << ' ';
      print(print, p[*j]);
    }
    else print(print, *j-1);
  };
  print(print, n-1);
  return ans;
}

int main() {
  vector<int> v {2, 4, 4, 7, 2, 1};
  vector<optional<int>> p {nullopt, nullopt, 0, nullopt, 2, 2};
  cout << weighted_interval(v, p) << '\n';
  return 0;
}
