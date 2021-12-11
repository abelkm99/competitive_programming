#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &arr) {
    vector<int> ans(3, 0);
    for (int x : arr) {
      ans[x]++;
    }
    int index = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < ans[i]; j++) {
        arr[index] = i;
        index++;
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
