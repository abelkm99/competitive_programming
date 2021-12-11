#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> ans;
    vector<pair<float, int>> memo;
    for (int i = 0; i < points.size(); i++) {
      float val =
          sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
      memo.push_back({val, i});
    }
    sort(memo.begin(), memo.end());
    auto it = memo.begin();
    while (it != memo.end() && k--) {
      ans.push_back(points[it->second]);
      it++;
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
