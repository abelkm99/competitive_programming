#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve(vector<int> &arr, int n) {
  int index = n - 1;
  int key = arr[index];
  while (key < arr[index - 1] && index - 1 >= 0) {
    arr[index] = arr[index - 1];
    for (int x : arr)
      cout << x << " ";
    cout << endl;
    index--;
  }
  arr[index] = key;

  for (int x : arr)
    cout << x << " ";
  cout << endl;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;
  solve(arr, n);
  return 0;
}
