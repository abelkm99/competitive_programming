#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n;
  vector<int> arr(100, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x]++;
  }
  for (int i = 0; i < 100; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
