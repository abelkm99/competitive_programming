#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  13 8 4 1

  1,4,8,13

  8,4,1


  4*2 < 5+5

1,4,8,13
*/
int maxFrequency(vector<int> &arr, int k) {
  sort(arr.begin(), arr.end());
  int l = 0;
  int r = 0;
  int large = INT_MIN;
  int total = 0;
  while (r < arr.size()) {
    total += arr[r];
    while (arr[r] * (r - l + 1) > total + k) {
      total -= arr[l];
      l++;
    }
    large = max(large, r - l + 1);
    r++;
  }
  return large;
}
int maxFrequency0(vector<int> &nums, int k) {
  sort(nums.rbegin(), nums.rend());
  int large = INT_MIN;
  int i = 0;
  while (i < nums.size()) {
    int val = k;
    int j = i + 1;
    int counter = 0;
    while (j < nums.size() && val > 0) {
      int rem = abs(nums[i] - nums[j]);
      if (val >= rem) {
        counter++;
        val -= rem;
      }
      j++;
    }

    large = max(counter, large);
    i++;
  }
  return large + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 4, 8, 13};
  cout << maxFrequency(arr, 5) << endl;
  return 0;
}
