#include <bits/stdc++.h>
#include <climits>
#define ll long long
#define pb push_back
using namespace std;
/*
  84,-37,32,40,95   167
  84  0 , 32,40,95
  -28,81,-20,28,-29 89
  0   81  0   28 0   89

 * */
void printdq(deque<int> d) {
  cout << "p----------\n";
  while (!d.empty()) {
    cout << d.front() << " ";
    d.pop_front();
  }
  cout << endl;
}
int prefix_sum(vector<int> &nums, int k) {
  vector<int> prefix_sum(nums.size() + 1, 0);
  for (int i = 0; i < nums.size(); i++) {
    prefix_sum[i + 1] = nums[i] + prefix_sum[i];
  }
  for (int x : prefix_sum)
    cout << x << " ";
  cout << "\n";
  deque<int> d;
  int ans = INT_MAX;
  for (int i = 0; i < nums.size() + 1; i++) {
    cout << i << " iteration\n";
    printdq(d);
    while (!d.empty() && prefix_sum[i] - prefix_sum[d.front()] >= k) {
      cout << d.front() << "removing this front \n";
      ans = min(i - d.front(), ans);
      d.pop_front();
    }
    while (!d.empty() && prefix_sum[i] <= prefix_sum[d.back()]) {
      cout << d.back() << " greedy pop the last \n";
      d.pop_back();
    }
    d.push_back(i);
  }
  if (ans == INT_MAX) {
    ans = -1;
  }
  return ans;
}
int solution_two(vector<int> &nums, int k) {
  int l = 0;
  int r = 0;
  int ans = INT_MAX;
  int total = 0;
  unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] <= 0) {
      mp.insert({i, nums[i]});
      nums[i] = 0;
    }
  }
  while (r < nums.size()) {
    total += nums[r];
    if (total >= k) {
      // check for the l and continue whith the maximum possibl
      int l_original = 1;
      int total_cp = total;
      while (l < r) {
        if (nums[l] == 0) {
          int val = mp[l];
          if (total - val > k) {
            ans = min(ans, r - l + 1);
          } else {
            l++;
          }
        } else {
        }
      }
    }
  }
  if (ans == INT_MAX)
    ans = -1;
  return ans;
}
int shortestSubarray(vector<int> &nums, int k) {
  int l = 0;
  int r = 0;
  int ans = INT_MAX;
  int total = 0;
  while (r < nums.size()) {
    total += nums[r];
    if (total >= k) {
      int l_original = l;
      int total_cp = total;
      while (l < r) {
        total -= nums[l];
        l++;
        if (total >= k) {
          if (r - l + 1 <= ans) {
            ans = r - l + 1;
            total_cp = total;
            l_original = l;
          }
        }
      }
      total = total_cp;
      l = l_original;
    }
    while (total >= k) {
      ans = min(ans, r - l + 1);
      total -= nums[l];
      l++;
    }
    r++;
  }
  if (ans == INT_MAX)
    ans = -1;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {84, -37, 32, 40, 95};
  cout << prefix_sum(nums, 167) << endl;
  return 0;
}
