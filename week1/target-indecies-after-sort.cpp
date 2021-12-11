#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

// ----------------------- solution

class Solution {
public:
  vector<int> targetIndices(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = arr.size() - 1;
    int m = l + (r - l) / 2;
    bool flag = false;
    while (l <= r) {
      m = l + (r - l) / 2;
      // cout << m << endl;
      if (arr[m] == target) {
        flag = true;
        break;
      }
      if (arr[m] > target) {
        r = m - 1;
      }
      if (arr[m] < target) {
        l = m + 1;
      }
    }
    vector<int> ans;
    int start = m;
    int end = m;
    if (flag == false)
      return ans;
    while (start >= 0 && arr[start] == target) {
      start--;
    }
    while (end < arr.size() && arr[end] == target) {
      end++;
    }
    for (int i = start + 1; i < end; i++) {
      ans.push_back(i);
    }
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
