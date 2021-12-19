#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int minSetSize(vector<int> &arr) {
  map<int, int> m;
  for (auto x : arr) {
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

  auto it = m2.rbegin();
  int half = arr.size() / 2;
  int counter = 0;
  while (it != m2.rend() && half > 0) {
    half -= it->first;
    counter++;
    it++;
  }

  return counter;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {9, 77, 63, 22, 92, 9,  14, 54,
                     8, 38, 18, 19, 38, 68, 58, 19};
  cout << minSetSize(arr) << endl;
  return 0;
}
