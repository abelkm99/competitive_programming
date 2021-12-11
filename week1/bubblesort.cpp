#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve(vector<int> &arr, int n) {
  int swaps = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
        swaps++;
      }
    }
  }
  cout << "Array is sorted in " << swaps << " swaps.\n";
  cout << "First Element: " << arr[0] << endl;
  cout << "Last Element: " << arr[n - 1] << endl;
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
