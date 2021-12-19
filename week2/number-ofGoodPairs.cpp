#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int numIdenticalPairs(vector<int> &arr) {
  map<int, int> m;
  for (int x : arr) {
    if (m[x]) {
      m[x]++;
    } else {
      m[x] = 1;
    }
  }
  int total = 0;
  for (auto x : m) {
    if (x.second > 1) {
      int n = x.second - 1;
      total += (n * (n + 1)) / 2;
    }
  }
  return total;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 2, 3, 1, 1, 3};
  cout << numIdenticalPairs(arr) << endl;
  return 0;
}
