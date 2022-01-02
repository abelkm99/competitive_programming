#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int> closestNumbers(vector<int> arr) {
  sort(arr.begin(), arr.end());
  // vector<pair<int,int>> diff;
  map<int, vector<int>> mp;
  for (int i = 0; i < arr.size() - 1; i++) {
    cout << arr[i] << " " << arr[i + 1] << endl;
    int diff = arr[i + 1] - arr[i];

    if (mp.find(diff) != mp.end()) {
      // cout << "here to add\n";
      // cout << "done here\n";
      mp[diff].push_back(arr[i]);
      mp[diff].push_back(arr[i + 1]);
    } else {
      vector<int> vals = {arr[i], arr[i + 1]};
      mp[diff] = vals;
    }
  }
  auto it = mp.begin();
  return it->second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {-20,      -3916237, -357920, -3620601, 7374819,
                     -7330761, 30,       6246457, -6461594, 266854};
  vector<int> ans = closestNumbers(arr);
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
