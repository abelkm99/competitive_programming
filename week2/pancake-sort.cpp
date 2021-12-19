#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*

   3->0  index+0
   0->1  index+1 =
   1->2  index+1

  3 2 4 1 -> 3
  4 2 3 1 -> 4
  1 3 2 4 -> 2
  3 1 2 4 -> 3
  2 1 3 4 -> 2
  1 2 3 4

*/

void print_mp(map<int, int> &mp) {
  for (auto x : mp) {
    cout << x.first << " " << x.second << endl;
  }
}

vector<int> pancakeSort(vector<int> &arr) {
  map<int, int> mp;
  vector<int> ans;
  for (int i = 0; i < arr.size(); i++) {
    mp.insert({arr[i], i});
  }

  auto it = mp.rbegin();
  int true_position = arr.size() - 1;
  while (it != mp.rend()) {
    cout << true_position << endl;
    if (it->second != true_position) {
      // true_position 4 -> 1
      // ans.push_back(true_position+1);
      // if the last is already on the first just do the invert;
      if (it->second != 0)
        ans.push_back(it->second + 1);
      auto updater = mp.begin();
      int update_count = true_position;
      while (updater != mp.end() && update_count) {
        if (updater->second < it->second) {
          updater->second += (true_position - it->second);
        } else if (updater->second > it->second) {
          updater->second = true_position - updater->second;
        }
        update_count--;
        updater++;
      }
      // add the final to its position
      ans.push_back(true_position + 1);
      it->second = true_position;
    }
    print_mp(mp);
    it++;
    true_position--;
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 4, 2, 3};
  vector<int> ans = pancakeSort(arr);
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
