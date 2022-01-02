#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  int maxArea(vector<int> &arr) {
    int ans = 0;
    int l = 0;
    int r = arr.size() - 1;
    while (l < r) {
      // cout<<l<<" "<<r<<endl;
      int area = min(arr[l], arr[r]) * (r - l);
      ans = max(ans, area);
      if (arr[l] <= arr[r]) {
        l++;
      } else {
        r--;
      }
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
