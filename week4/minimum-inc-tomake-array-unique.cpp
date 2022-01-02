#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  long long minIncrementForUnique(vector<int> &nums) {
    int sm = INT_MAX;
    int lg = INT_MIN;
    for (int x : nums) {
      sm = min(x, sm);
      lg = max(x, lg);
    }
    map<int, int> mp;
    for (int x : nums) {
      if (mp[x])
        mp[x]++;
      else
        mp[x] = 1;
    };
    vector<int> free_space;
    for (int i = lg; i >= sm; i--) {
      if (mp[i]) {

      } else {
        free_space.push_back(i);
      }
    }
    //         cout<<"print free space\n";
    //         for(int x:free_space) cout<<x<<" ";
    //         cout<<endl;

    vector<int> dups;
    for (auto x : mp) {
      if (x.second > 1) {
        for (int i = 0; i < x.second - 1; i++) {
          dups.push_back(x.first);
        }
      }
    }
    // cout<<"print dups\n";
    // for(int x:dups) cout<<x<<" ";
    // cout<<endl;

    int i = 0;
    long long ans = 0;
    while (i < dups.size() && free_space.size()) {
      if (free_space.back() > dups[i]) {
        ans += abs(free_space.back() - dups[i]);
        free_space.pop_back();
        i++;
      } else {
        free_space.pop_back();
      }
    }
    int j = lg + 1;
    while (i < dups.size()) {
      // cout<<j-dups[i]<<endl;
      ans += abs(j - dups[i]);
      j++;
      i++;
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
