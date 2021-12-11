#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &arr) {
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  int i = 0;
  while (i < arr.size()) {
    int start = arr[i][0];
    int end = arr[i][1];
    int j = i + 1;
    while (j < arr.size()) {
      if (end >= arr[j][0]) {
        end = max(end, arr[j][1]);
        j++;
      } else {
        break;
      }
    }
    ans.push_back(vector<int>{start, end});
    i = j;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> arr = {{1, 4}, {2, 3}};
  vector<vector<int>> ans = merge(arr);
  for (auto v : ans) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
