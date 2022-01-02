#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  int hIndex(vector<int> &arr) {
    /*
        0 1 3 5 6

        6  1,4
        5  2,3
        3  3,2
        1  4,1
        0  5,0


        1 1 3
        based on a > b;
        3 1
        1 3

    */
    sort(arr.rbegin(), arr.rend());
    int i = 0;
    int ans = 0;
    while (i < arr.size()) {
      if (arr[i] >= i + 1) {
        ans = i + 1;
      }
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
