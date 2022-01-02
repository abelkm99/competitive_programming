#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  10 3 10

  5 0 5

  2 1 2

  1 0 1

  15;
  1 15
  1 7
  8 15

  1 3
  4 7


  1
  2
  3
  1 / 0
  1 / 1

  15/2->7;

  1-7, 8 ,9-15;

  7 ->   1,2,3 4,5,6

*/
ll solve2(ll n, ll l, ll r, ll cur_min, ll cur_max) {
  // cout << "n -> " << n << " cur_min-> " << cur_min << " cur_max-> " <<
  // cur_max
  //      << endl;
  ll m = cur_min + (cur_max - cur_min) / 2;
  // while (cur_min < l && cur_min < m) {
  //   cur_min++;
  //   cout << "adding 1 to the mid " << cur_min << endl;
  // }
  // while (cur_max > r && cur_max > m) {
  //   cur_max--;
  //   cout << "decrement 1 to the the max " << cur_max << endl;
  // }
  if (cur_min > r && cur_max > r) {
    return 0;
  }
  if (cur_min < l && cur_max < l) {
    return 0;
  }
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return solve2(n / 2, l, r, cur_min, m - 1) + solve2(n % 2, l, r, m, m) +
         solve2(n / 2, l, r, m + 1, cur_max);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, l, r;
  cin >> n >> l >> r;
  ll max_val = 0;
  while (max_val < n) {
    max_val *= 2;
    max_val++;
  }
  // cout << max_val << endl;
  cout << solve2(n, l, r, 1ll, max_val) << "\n";
  // solve(n, l, ++;r);
  return 0;
}
