#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
#define ll long long
class Solution {
public:
  long long power(ll num, ll times, int mod) {
    if (times == 0)
      return 1;
    ll result = power(num, times / 2, mod) % mod;
    return (result * result) * (times % 2 ? num : 1) % mod;
  }

  int countGoodNumbers(long long n) {
    int mod = 1e9 + 7;
    ll e = n / 2;
    ll o = e;
    if (n % 2)
      o++;
    return (power(5, o, mod) * power(4, e, mod)) % mod;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
