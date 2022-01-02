#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    double res;
    res = myPow(x, n / 2);
    res *= res;
    if (n % 2) {
      if (n < 0) {
        res *= (1 / x);
      } else {
        res *= x;
      }
    }
    return res;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
