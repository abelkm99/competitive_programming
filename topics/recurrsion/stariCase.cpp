#include <bits/stdc++.h>
#include <numeric>
#define ll long long
#define pb push_back
using namespace std;

void stairPermute(int &val,vector<int> &dereja, int n, int index) {
  ll total = accumulate(dereja.begin(), dereja.end(), 00L);
  for (int i = 1; i <= 3; i++) {
    dereja.push_back(i);
    ll total = accumulate(dereja.begin(), dereja.end(), 00L);
    if (total >= n) {
      // for (int x : dereja)
      //   cout << x << " ";
      // cout << endl;
      val++;
      dereja.pop_back();
      return;
    }
    stairPermute(val,dereja, n, i);
    dereja.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int s, n;
  cin >> s;
  while (s--) {
    cin >> n;
    vector<int> arr;
    int val = 0;
    stairPermute(val, arr, n, 1);
    cout<<val<<endl;
  }
  // vector<int> arr;
  // int val = 0;
  // stairPermute(val,arr, 7, 1);
  // cout<<val<<endl;
  return 0;
}
