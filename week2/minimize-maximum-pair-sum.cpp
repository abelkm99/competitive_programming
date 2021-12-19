#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int minPairSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int l = 0, r = nums.size() - 1;
  int ans = 0;
  while (l < r) {
    cout << nums[l] << " " << nums[r] << endl;
    ans = max(nums[l] + nums[r], ans);
    l++;
    r--;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {3, 5, 2, 3};
  cout << minPairSum(arr) << endl;
  return 0;
}
