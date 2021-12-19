#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  1,2,3

  1
  1,2
  1,2,3


  abc bc   c      []
  [] [a] [a,b] [a,b,c]

        [a,c]
    [b]   [b,c]

*/
void combination(vector<int> &arr, vector<vector<int>> &ans, vector<int> temp,
                 int index) {
  ans.push_back(temp);
  for (int i = index; i < arr.size(); i++) {
    temp.push_back(arr[i]);
    combination(arr, ans, temp, i + 1);
    temp.pop_back();
  }
}
vector<vector<int>> subset(vector<int> &arr) {
  vector<int> temp;
  vector<vector<int>> ans;
  combination(arr, ans, temp, 0);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> ans = subset(arr);
  for (auto v : ans) {
    for (auto x : v)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}
