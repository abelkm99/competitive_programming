#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int BS(vector<int> &arr, int target) {
  int l = 0;
  int r = arr.size() - 1;
  while (l <= r) {
    int m = l + (r - 1) / 2;
    if (arr[m] == target) {
      return m;
    }
    if (arr[m] < target) {
      l = m + 1;
    }
    if (arr[m] > target) {
      r = m - 1;
    }
  }
  return -1;
}
vector<int> binary_search(vector<int> &arr, int target) {
  sort(arr.begin(), arr.end());
  int l = 0;
  int r = arr.size() - 1;
  int m = l + (r - l) / 2;
  bool flag = false;
  while (l <= r) {
    m = l + (r - l) / 2;
    // cout << m << endl;
    if (arr[m] == target) {
      flag = true;
      break;
    }
    if (arr[m] > target) {
      r = m - 1;
    }
    if (arr[m] < target) {
      l = m + 1;
    }
  }
  vector<int> ans;
  int start = m;
  int end = m;
  if (flag == false)
    return ans;
  while (start>=0 && end<arr.size() && ( arr[start] == target || arr[end] == target) ) {
    if (arr[start] == target)
      start--;
    if (arr[end] == target)
      end++;
  }
  for (int i = start + 1; i < end; i++) {
    ans.push_back(i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  int target;
  cin >> n >> target;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;
  vector<int> ans = binary_search(arr, target);
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  // cout << BS(arr, target) << endl;
  return 0;
}
