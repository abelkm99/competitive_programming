#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
   4 2 0 3 2 5
   0 1 2 3 4 5
        1
   1    1
   1  1 1
   11 111
   11 111

  2  1 0 1 3

       1
   1   1
   11 11

   01234
   4-0-1

   5 2 1 3
   0 1 2 3

   1
   1
   1  1
   11 1
   1111
   0  3

     1
   1 1
   111

 * */
int trap(vector<int> &arr) {
  int ans = 0;
  int i = 0;
  stack<int> s;
  while (i < arr.size()) {
    if (s.empty() || arr[s.top()] >= arr[i]) {
      s.push(i);
      i++;
    } else {
      int t = s.top();
      s.pop();
      if (!s.empty()) {
        int mx = min(arr[s.top()], arr[i]);
        ans += (mx - arr[t]) * (i - s.top() - 1);
        cout << ans << endl;
      }
    }
  }
  return ans;
}
int trap2(vector<int> &arr) {
  stack<int> s;
  int i = 0;
  int ans = 0;
  int temp_ans = 0;
  int blocks = 0;
  while (i < arr.size()) {
    cout << "----------------" << i << "-------------------\n";
    if (s.empty() || arr[s.top()] >= arr[i]) {
      s.push(i);
    } else {
      cout << "starting to pop  at " << arr[i] << " and index " << i << endl;
      int last = 0;
      int before_val_blocks = blocks;
      while (!s.empty() && arr[s.top()] <= arr[i]) {
        blocks += arr[s.top()];
        last = s.top();
        s.pop();
        cout << "blocks added " << blocks << endl;
      }

      if (s.empty()) {
        cout << "last is " << arr[last] << " and index is " << last << endl;
        blocks -= arr[last];
        cout << "stack is empty\n";
        int diff = (i - last - 1) * min(arr[i], arr[last]);
        cout << "final diff " << diff - blocks << endl;
        diff -= blocks;
        ans += diff;
        blocks = 0;
        temp_ans = 0;
      } else {
        cout << "last is " << arr[s.top()] << " and index is " << s.top()
             << endl;
        int diff = (i - s.top() - 1) * min(arr[i], arr[s.top()]);
        diff -= blocks - before_val_blocks;
        temp_ans += diff;
      }
      s.push(i);
      cout << "temp ans is " << temp_ans << endl;
      cout << "real ans is " << ans << endl;
    }
    i++;
  }
  cout << "final blocks is " << blocks << endl;
  return ans += temp_ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // vector<int> arr = {4,2,0,3,2,5};
  // vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> arr = {0, 7, 1, 4, 6};
  // vector<int> arr = {9, 6, 8, 8, 5, 6, 3};
  for (int x : arr)
    cout << x << " ";
  cout << endl;
  cout << trap(arr) << endl;
  return 0;
}
