#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  4 4  4 4

  (4 * 4 ) * (4*4)
  2 , -2

  (-1)
  -1%2
  0.5*0.5
*/
long long power(ll num, ll times) {
  if (times == 0)
    return 1;
  if (times == 1)
    return num;
  return power(num, times / 2) * power(num, times / 2) * (times % 2 ? num : 1);
}
long long power(ll num, ll times, int mod) {
  if (times == 0)
    return 1;
  ll result = power(num, times / 2) % mod;
  return (result * result) * (times % 2 ? num : 1) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll num = 5;
  ll times = 25;
  int mod = 1e9 + 7;
  cout << power(5, 25, mod) << endl;
  cout << power(4, 25, mod) << endl;
  return 0;
}
