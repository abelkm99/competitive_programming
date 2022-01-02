#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  int solve(vector<int> &nums, int l, int r,
            vector<vector<pair<int, bool>>> &dp) {
    if (l == r)
      return nums[l];
    if (l > r)
      return 0;
    if (dp[l][r].second == true) {
      return dp[l][r].first;
    }
    int left = nums[l] - solve(nums, l + 1, r, dp);
    int right = nums[r] - solve(nums, l, r - 1, dp);
    dp[l][r] = {max(left, right), true};
    return dp[l][r].first;
  }
  bool PredictTheWinner(vector<int> &nums) {
    vector<vector<pair<int, bool>>> dp(
        nums.size() + 1, vector<pair<int, bool>>(nums.size() + 1, {0, false}));
    int ans = solve(nums, 0, nums.size() - 1, dp);
    return ans >= 0;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 5, 2};
  Solution *s = new Solution();
  cout << s->PredictTheWinner(arr) << endl;
  return 0;
}
