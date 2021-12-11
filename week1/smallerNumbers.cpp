#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  int binary_search(vector<int> &arr, int target) {
    int l = 0;
    int r = arr.size() - 1;
    bool flag = false;
    int m = 0;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (arr[m] == target) {
        flag = true;
        break;
      }
      if (arr[m] < target) {
        l = m + 1;
      }
      if (arr[m] > target) {
        r = m - 1;
      }
    }
    if (flag) {
      while (m >= 0 && arr[m] == target) {
        m--;
      }
      return m + 1;
    }
    return -1;
  }
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> sorted;
    for (int x : nums)
      sorted.push_back(x);
    sort(sorted.begin(), sorted.end());

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      ans.push_back(binary_search(sorted, nums[i]));
    }
    return ans;
  }
};
/*
    1 2 2 3 8
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
