#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  1,2,2,3,7,8

  9,8,7, 6,5,1 2,3,4
  make a triplet where the second number can be the max

  981   762   5,4,3
  8 6 4
  18 got it soo

  987654321
   1 1 1

 */
int maxCoins(vector<int> &arr) {
  sort(arr.rbegin(), arr.rend());
  int ans = 0;
  for (int i = 1; i < arr.size() - (arr.size)/3; i += 2) {
    ans += arr[i];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {2,4,5};
  cout << maxCoins(arr) << endl;
  return 0;
}
