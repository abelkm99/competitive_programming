#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#define ll long long
#define pb push_back
using namespace std;
/*
   assuming they are in reverse order
   1 2 2 2 3 3 4 6 7

   6 4 3 3 1 1

*/
void back_tracking_method(vector<int> &arr, vector<int> memo, int k,
                          int &shortest, int total_sum, int depth) {
  if (total_sum >= k) {
    for (int i = 0; i < arr.size(); i++) {
      if (memo[i]) {
        cout << arr[i] << " ";
      } else {
        // cout << 0 << " ";
      }
    }
    cout << "\n";
    shortest = min(shortest, depth);
    int total = count(memo.begin(), memo.end(), 1);
    shortest = min(total, shortest);
    return;
  }
  for (int i = depth; i < arr.size(); i++) {
    if (memo[i] == 0) {
      // cout << "here\n";
      memo[i] = 1;
      back_tracking_method(arr, memo, k, shortest, total_sum + arr[i],
                           depth + 1);
      memo[i] = 0;
    }
  }
}

int shortestSubarray(vector<int> &nums, int k) {
  int total_sum = 0;
  int shortest = INT_MAX;
  vector<int> memo(nums.size(), 0);
  // sort(nums.rbegin(), nums.rend());
  back_tracking_method(nums, memo, k, shortest, total_sum, 0);
  if (shortest == INT_MAX)
    shortest = -1;
  return shortest;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr;
  for (int i = 14; i >= 1; i--) {
    arr.push_back(i);
  }
  for (int x : arr) {
    cout << x << " ";
  }
  cout << '\n';
  cout << shortestSubarray(arr, 100);
  return 0;
}
