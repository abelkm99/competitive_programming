#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  1234

  13334

*/
int maxOperations(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  int counter = 0;
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    if (nums[l] + nums[r] == k) {
      l++;
      r--;
      counter++;
    }
    if (nums[l] + nums[r] < k) {
      l++;
    }
    if (nums[l] + nums[r] > k) {
      r--;
    }
  }
  return counter;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {3, 1, 3, 4, 3};
  int k = 6;
  cout << maxOperations(arr, k) << endl;
  return 0;
}
