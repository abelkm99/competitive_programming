#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int> rearrangeArray(vector<int> &nums) {
  vector<int> ans;
  sort(nums.begin(), nums.end());
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    ans.push_back(nums[l]);
    ans.push_back(nums[r]);
    l++;
    r--;
  }
  if (l == r)
    ans.push_back(nums[l]);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
