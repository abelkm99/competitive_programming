#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define pb push_back
using namespace std;

void solve(vector<int> &arr, int n) {
  for (int i = 0; i < arr.size(); i++) {
    int small = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[small])
        small = j;
    }
    swap(arr[i], arr[small]);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
      cin >> x;
    solve(arr, n);
    for (int x : arr)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}
