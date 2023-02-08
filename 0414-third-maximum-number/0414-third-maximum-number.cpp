class Solution {
public:
  int thirdMax(vector<int> &nums) {
    set<int, greater<int>> s;
    set<int>::iterator itr;

    for (auto i : nums) {
      s.insert(i);
    }
    itr = s.begin();
    if (s.size() == 1) {
      return *itr;
    } else if (s.size() == 2) {
      return *(itr++);
    } else {
      itr++;
      return *(++itr);
    }
  }
};
