#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

/*
    search the min
    get the maximum

    456 6-4 = 2
    4569  5 != range -1
    val @indexs == max-min

    3 5 7 9
    9-3 = 6
    3+6 = 9
    pattern = 6/3 = 2;

    456
    6-4 = 2%2 = 0;

    4567
    9-4 = 5

    5%3 =
*/
vector<bool> solution_two(vector<int> &nums, vector<int> &l, vector<int> &r) {
  vector<bool> ans;
  for (int i = 0; i < l.size(); i++) {
    int sm = INT_MAX;
    int lg = INT_MIN;
    for (int j = l[i]; j <= l[i]; j++) {
      sm = min(sm, nums[j]);
      lg = max(lg, nums[j]);
    }
    int dist = abs(lg - sm);
    int qurey_length = abs(r[i] - l[i]);
    if (dist % qurey_length) {
      ans.push_back(false);
    } else {
      int pattern = dist / qurey_length;
      vector<int> search_space(abs(sm) + lg + 1, 0);
      for (int j = l[i]; j <= r[i]; j++) {
        search_space[nums[j] + abs(sm)]++;
      }
      bool has_answer = true;
      for (int j = abs(sm); j < search_space.size(); j += pattern) {
        if (search_space[j] == 0) {
          has_answer = false;
          break;
        } else {
          search_space[j]--;
        }
      }
      ans.push_back(has_answer);
    }
  }
  return ans;
}
vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                      vector<int> &r) {
  vector<bool> ans;
  for (int i = 0; i < l.size(); i++) {
    // search for max and min the l and r range
    vector<int> temp;
    for (int j = l[i]; j <= r[i]; j++) {
      temp.push_back(nums[j]);
    }
    sort(temp.begin(), temp.end());
    int sm = temp[0];
    int lg = temp[temp.size() - 1];
    if ((lg - sm) % abs(r[i] - l[i])) {
      ans.push_back(false);
    } else {
      int rg = (lg - sm) / abs(r[i] - l[i]);
      bool res = true;
      for (int j = 0; j < temp.size() - 1; j++) {
        if (temp[j] + rg != temp[j + 1]) {
          res = false;
          break;
        }
      }
      ans.push_back(res);
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
