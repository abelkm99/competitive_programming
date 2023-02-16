class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
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
      }else{
          return {};
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
};