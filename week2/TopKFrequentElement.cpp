#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  5,5,5,5,5,1,1,1,2,2,3

  1 3
  2 2
  3 1
  5 6

  //
  1 3
  2 2
  3 1
*/
vector<int> topKFrequent(vector<int> &nums, int k) {
  map<int, int> m;
  for (int x : nums) {
    if (m[x]) {
      m[x]++;
    } else {
      m[x] = 1;
    }
  }
  multimap<int, int> m2;
  for (auto x : m) {
    m2.insert({x.second, x.first});
  }
  vector<int> ans;
  for (auto it = m2.rbegin(); it != m2.rend() && k; it++) {
    ans.push_back(it->second);
    k--;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 2};
  int k = 1;
  vector<int> ans = topKFrequent(arr, 2);
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
