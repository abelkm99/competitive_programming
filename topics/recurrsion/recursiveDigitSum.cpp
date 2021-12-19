#include <bits/stdc++.h>
#include <sys/types.h>
#define ll long long
#define pb push_back
using namespace std;
/*
    10+9+5+7 =
    18 + 9 = 18+
    10+9 = 19
    19+
    string sum;
    1e9 9
    9*5*1000000;
    99;

*/
string recursive_sum(string s) {
  if (s.length() == 1)
    return s;
  u_int64_t total = 0;
  for (int i = 0; i < s.length(); i++) {
    total += s[i] - '0';
  }
  return recursive_sum(to_string(total));
}

void solve(string s, int n) {
  string val = "";
  for (int i = 0; i < n; i++) {
    val += s;
  }
  s = val;
  cout << recursive_sum(s) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  int n;
  cin >> s >> n;
  solve(s, n);
  return 0;
}
