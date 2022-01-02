#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  /*
      n  = 3
    [0,-1];
  */
  int kthGrammar(double n, double k) {
    // cout << n << " " << k << endl;
    if (n == 1)
      return 0;
    int parent = kthGrammar(n - 1, ceil(k / 2));
    // cout << "returned " << parent << " for " << n - 1 << " and " << ceil(k /
    // 2)
    //      << endl;
    // cout << "and compute for " << n << " and " << k << endl;
    if (parent == 0) {
      if ((int)k % 2) {
        return 0;
      } else {
        return 1;
      }
    } else {
      if ((int)k % 2)
        return 1;
      else
        return 0;
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Solution *s = new Solution();
  int n;
  int k;
  cin >> n;
  cin >> k;
  cout << s->kthGrammar(n, k) << endl;
  // cout << ceil(1.0 / 2) << endl;
  return 0;
}
