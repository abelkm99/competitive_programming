#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int> final_approach(vector<int> &arr) {
  if (arr.size() % 2)
    return {};
  map<int, int> m;
  for (int x : arr) {
    if (m[x]) {
      m[x]++;
    } else {
      m[x] = 1;
    }
  }
  vector<int> ans;
  vector<int> memo(100005, 0);
  for (auto x : m) {
    if (m[x.first] && x.first != 0) {
      if (x.second <= m[x.first * 2]) {
        for (int i = 0; i < x.second; i++) {
          ans.push_back(x.first);
        }
        m[x.first * 2] -= x.second;
      }
      // cout << x.first << " " << x.second << endl;
      memo[x.first * 2] = 1;
    } else if (x.first == 0) {
      if (x.second % 2 == 0) {
        for (int i = 0; i < x.second / 2; i++) {
          ans.push_back(0);
        }
      } else {
        return {};
      }
    }
  }
  return ans;
}
int binary_s(vector<int> &arr, int target, int start, int end) {
  int l = start;
  int r = end;
  int mid = l + (r - l) / 2;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] > target) {
      r = mid - 1;
    }
    if (arr[mid] < target) {
      l = mid + 1;
    }
  }
  return -1;
}
bool any_other(vector<int> &arr, vector<int> &memo, int target, int index) {
  int l_search = index;
  int r_search = index;
  while (arr[l_search] == target && l_search >= 0) {
    if (memo[l_search] == 0) {
      memo[l_search] = 1;
      return true;
    }
    l_search--;
  }
  while (arr[r_search] == target && r_search < arr.size()) {
    if (memo[r_search] == 0) {
      memo[r_search] = 1;
      return true;
    }
    r_search++;
  }
  return false;
}
vector<int> findOriginalArray(vector<int> &changed) {
  vector<int> ans;
  vector<int> none;
  if (changed.size() % 2)
    return none;
  sort(changed.begin(), changed.end());
  vector<int> memo(changed.size(), 0);
  ll num_zero = 0;
  while (num_zero + 1 < changed.size() && changed[num_zero] == 0 &&
         changed[num_zero + 1] == 0) {
    num_zero += 2;
    ans.push_back(0);
  }
  for (int i = num_zero; i < changed.size(); i++) {
    if (!memo[i]) {
      memo[i] = 1;
      int res = binary_s(changed, changed[i] * 2, i + 1, changed.size() - 1);
      if (res == -1) {
        return none;
      } else {
        // look for any other
        if (any_other(changed, memo, changed[i] * 2, res)) {
          ans.push_back(changed[i]);
        } else {
          return none;
        }
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // vector<int> changed = {2, 1, 2, 4, 2, 4};
  vector<int> changed(100000, 0);
  vector<int> ans = final_approach(changed);
  for (int x : ans)
    cout << x << endl;
  return 0;
}
