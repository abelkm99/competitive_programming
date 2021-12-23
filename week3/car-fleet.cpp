#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define pb push_back
using namespace std;
/*
 10,2
 8,4,
 0,1
 5,1
 3,3


 10,1
 8,1
 7,1
 5,7
 3,3
 0,12

4 6
2 3
0 5

6,3,5


8 1
6 2


*/
int carFleet(int target, vector<int> &pos, vector<int> speed) {
  vector<pair<int, double>> arr;
  for (int i = 0; i < pos.size(); i++) {
    double mx = ((double)(target)-pos[i]) / speed[i];
    arr.push_back({pos[i], mx});
  }

  sort(arr.rbegin(), arr.rend());
  for (auto x : arr) {
    cout << x.first << " " << x.second << endl;
  }
  int counter = 0;
  int i = 0;
  while (i < arr.size()) {
    int j = i + 1;
    counter++;
    while (j < arr.size() && arr[j].second <= arr[i].second) {
      j++;
    }
    i = j;
  }
  // stack<int> s;

  // for (auto x : arr) {
  //   if (!s.empty() && s.top() < x.second) {
  //     counter++;
  //     while (!s.empty() && s.top() < x.second) {
  //       s.pop();
  //     }
  //     s.push(x.second);

  //   } else {
  //     s.push(x.second);
  //   }
  // }
  // if (!s.empty())
  //   counter++;
  return counter;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // vector<int> pos = {0, 2, 4};
  // vector<int> speed = {4, 2, 1};
  vector<int> pos = {8, 3, 7, 4, 6, 5};
  vector<int> speed = {4, 4, 4, 4, 4, 4};
  int target = 10;
  cout << carFleet(target, pos, speed) << endl;
  return 0;
}
