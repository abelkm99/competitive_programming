#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  ll fib2(int n, vector<ll> &arr) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    if (arr[n] != -1) {
      return arr[n];
    }

    arr[n] = fib2(n - 1, arr) + fib2(n - 2, arr);
    return arr[n];
  }

  ll fib(int n) {
    vector<ll> arr(n + 1, -1);
    return fib2(n, arr);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
