#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*

  1  2  3  4

  1,2 1,3 1,4

  1,2,3 1,2,4

  1,2,3,4

  1,2,4,3

  1,2,4
  a b c
    b c
      c
    c b
      b
    b c
  b a c
*/
void perm(vector<int> &arr, vector<vector<int>> &ans, vector<int> memo,
          int index) {
  if (index == arr.size()) {
    vector<int> temp;
    for (int val : memo) {
      temp.push_back(arr[val]);
    }
    ans.push_back(temp);
    return;
  }
  for (int i = 0; i < memo.size(); i++) {
    if (memo[i] == -1) {
      memo[i] = index;
      perm(arr, ans, memo, index + 1);
      memo[i] = -1;
    }
  }
  return;
}

void permutation_modified(vector<char> &arr, vector<vector<char>> &ans, int n,
                          int x) {
  if (x == n) {
    ans.push_back(arr);
    return;
  }
  for (int i = x; i < n; i++) {
    swap(arr[i], arr[x]);
    permutation_modified(arr, ans, n, x + 1);
    swap(arr[i], arr[x]);
  }
}
void unique_permute(vector<int> &arr, vector<vector<int>> &ans, int index) {
  if (index == arr.size()) {
    ans.push_back(arr);
    return;
  }
  for (int i = index; i < arr.size(); i++) {
    if (index - 1 < 0 || arr[index] != arr[index - 1]) {
      swap(arr[index], arr[i]);
      unique_permute(arr, ans, index + 1);
      swap(arr[index], arr[i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<char> arr{'A', 'B', 'C'};
  vector<vector<char>> ans;
  vector<int> memo(arr.size(), -1);
  unique_permute(arr, ans, 0);
  // sort(ans.begin(), ans.end());
  for (auto v : ans) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
