#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll tri(ll n, vector<ll> &arr) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 1;
  if (arr[n] != -1) {
    return arr[n];
  }
  arr[n] = tri(n - 3, arr) + tri(n - 2, arr) + tri(n - 1, arr);
  return arr[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<ll> arr(n + 1, -1);
  cout << tri(n, arr) << endl;
  return 0;
}
