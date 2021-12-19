#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

vector<int> solve(vector<int> &arr1, vector<int> &arr2) {
  vector<int> ans;
  map<int, int> m1;
  map<int, int> m2;

  for (int x : arr1) {
    if (m1[x]) {
      m1[x]++;
    } else {
      m1[x] = 1;
    }
  }
  for (int x : arr2) {
    if (m2[x]) {
      m2[x]++;
    } else {
      m2[x] = 1;
    }
  }
  for (auto x : m1) {
    if (m2[x.first]) {
      ans.push_back(x.first);
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr1 = {1, 2, 3, 5, 6, 7};
  vector<int> arr2 = {3, 6, 7, 8, 20};
  vector<int> ans = solve(arr1, arr2);
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
