#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
 https://codeforces.com/contest/487/problem/B
        7 2 2
    1 3 1 2 4 1 2
    1 3 1 2

        [1,5,6,7,8,10,6,5,6]->4

        1,5,6

    3 3 2 2  ->4
    2 2 2 1
    1 1 1 r
    1

    2 2 1 1 -> 4



 * */

void solve(vector<int> &arr, int s, int limit) {
  int counter = 0;
  deque<int> increasing;
  deque<int> decreasing;
  int l = 0;
  int r = 0;
  while (r < arr.size()) {
    while (!increasing.empty() && arr[increasing.back()] >= arr[r]) {
      increasing.pop_back();
    }
    while (!decreasing.empty() && arr[decreasing.back()] <= arr[r])
      decreasing.pop_back();
  }
  increasing.push_back(r);
  decreasing.push_back(r);

  if (arr[decreasing.front()] - arr[increasing.front()] > l) {

  } else {
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, s, l;
  cin >> n >> s >> l;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;
  solve(arr);
  return 0;
}
