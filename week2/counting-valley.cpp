#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int height = 0;
  bool valley = false;
  int counter = 0;
  for (char c : s) {
    if (c == 'U') {
      height++;
    } else {
      height--;
    }
    if (height < 0) {
      valley = true;
    }
    if (height > -1 && valley) {
      counter++;
      valley = false;
    }
  }
  cout << counter << endl;
  return 0;
}
