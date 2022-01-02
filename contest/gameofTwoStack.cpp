#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  b= [17,1,1,1,8]
  a= [8,8,4,5,9]

  20+17
  37
  20

*/
int solve(int mx, vector<int> a, vector<int> b) {
  int i = 0;
  int j = 0;
  int sum = 0;
  int ans = 0;
  while (i < a.size() && sum + a[i] <= mx) {
    sum += a[i];
    i++;
  }
  ans = max(i, 0);
  while (j < b.size() && i >= 0) {
    // cout << b[j] << endl;
    sum += b[j];
    j++;
    while (sum > mx && i >= 0) {
      i--;
      sum -= a[i];
    }
    // cout << "sum is " << sum << " ";
    // cout << i << " " << j << endl;
    if (sum <= mx) {
      ans = max(ans, i + j);
    }
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  int l, m, mx;
  cin >> t;
  while (t--) {
    cin >> l >> m >> mx;
    vector<int> a(l);
    vector<int> b(m);
    for (auto &x : a)
      cin >> x;
    for (auto &x : b)
      cin >> x;
    cout << solve(mx, a, b) << endl;
  }
  return 0;
}
