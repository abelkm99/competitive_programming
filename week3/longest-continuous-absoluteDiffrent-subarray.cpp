#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
 *
        10, 1, 2, 4, 7, 2 ->   5

        10 - 1 = 9  pop and add 1;
        2 4 7 2


        [1,5,6,7,8,10,6,5,6]->4
        6,7,8,10,6,5
 * */
void print_d(priority_queue<int, vector<int>, greater<int>> d) {
  while (!d.empty()) {
    cout << d.top() << " ";
    d.pop();
  }
  cout << endl;
}
void print_d(priority_queue<int> d) {
  while (!d.empty()) {
    cout << d.top() << " ";
    d.pop();
  }
  cout << endl;
}

int solution_with_heap(vector<int> &nums, int limit) {
  // hold the value and the index;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minH;
  priority_queue<pair<int, int>> maxH;

  int l = 0;
  int r = 0;
  int ans = 0;
  while (r < nums.size()) {
    while (!minH.empty() && abs(nums[r] - minH.top().first) > limit) {
      // cout << "conflict with min \t";
      int nl = minH.top().second + 1;
      l = max(nl, l);
      minH.pop();
      // cout << "now left is " << nums[l] << endl;
    }
    while (!maxH.empty() && abs(nums[r] - maxH.top().first) > limit) {
      int nl = maxH.top().second + 1;
      l = max(nl, l);
      maxH.pop();
    }
    int diff = r - l + 1;
    // cout << r << "-" << l << "+1"
    //      << "=" << diff << endl;
    ans = max(ans, diff);
    // if (diff > ans)
    //   ans = diff;
    maxH.push({nums[r], r});
    minH.push({nums[r], r});
    r++;
  }

  return ans;
}

/**
 *
 * use sliding window which means streach to the right until the subset is valid
 * when streaching value check if both maximum and minimum are valid
 * */
int solution2(vector<int> &nums, int limit) {
  deque<int> increasing;
  deque<int> decreasing;
  int l = 0;
  int r = 0;
  int ans = 0;
  while (r < nums.size()) {
    int x = nums[r];
    while (!increasing.empty() && nums[increasing.back()] >= x) {
      increasing.pop_back();
    }
    while (!decreasing.empty() && nums[decreasing.back()] <= x) {
      decreasing.pop_back();
    }
    increasing.push_back(r);
    decreasing.push_back(r);
    if (nums[decreasing.front()] - nums[increasing.front()] > limit) {
      l++;
      if (l > increasing.front())
        increasing.pop_front();
      if (l > decreasing.front())
        decreasing.pop_front();
    } else {
      ans = max(ans, (r - l) + 1);
      r++;
    }
  }
  return ans;
}
int longestSubarray(vector<int> &nums, int limit) {
  int ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  int i = 0;
  while (i < nums.size()) {
    int j = i;
    cout << i << " ==== " << endl;
    while (!pq.empty() && j < nums.size() && abs(pq.top() - nums[j]) <= limit) {
      pq.push(nums[j]);
      int s = pq.size();
      ans = max(ans, s);
      j++;
      print_d(pq);
    }
    while (!pq.empty() && j < nums.size() && abs(pq.top() - nums[j]) > limit) {
      pq.pop();
    }
    if (j < nums.size()) {
      pq.push(nums[j]);
    }
    j++;
    i = j;
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // vector<int> arr = {1, 5, 6, 7, 8, 10, 6, 5, 6};
  vector<int> arr = {4, 2, 2, 2, 4, 4, 2, 2};
  int limit = 0;
  for (int x : arr)
    cout << x << " ";
  cout << endl;
  cout << solution_with_heap(arr, limit) << endl;
  return 0;
}

/*
  ans = 4;
  (decresing)  max = 6 5
  (increasing) min = 5
   in ques for minimum it has to be in decreasing order

*/
