#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void solve(vector<ll> &arr) {
  ll total = 0;
  bool waiting = false;
  for (int i = 0; i < arr.size(); i++) {
    total += arr[i] / 2;
    if (arr[i] % 2 && waiting) {
      total++;
      waiting = false;
    } else if (arr[i] % 2 && !waiting) {
      waiting = true;
    } else {
      waiting = false;
    }
  }
  cout << total << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (auto &x : arr)
    cin >> x;
  solve(arr);
  return 0;
}
