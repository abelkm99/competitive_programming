#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {-10, -12, -1, 0, 1, 2, 3, 4, 5};
  int val = find(arr.begin(), arr.end(), 100);
  cout << val << endl;
  return 0;
}
