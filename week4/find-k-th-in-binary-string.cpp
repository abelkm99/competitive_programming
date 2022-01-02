#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  /*
      001 110  011
      0011 1100 0011
      0 1 0
  */
  string get_s(int n, string s) {
    if (n == 0)
      return s;
    string reversed = s;
    if (s.length() % 2) {
      int mid = reversed.length() / 2;
      char c = (reversed[mid] == '0' ? '1' : '0');
      reversed[mid] = c;
    }
    // string temp = s+"1"+reversed;
    // cout<<temp<<" at "<<n<<endl;
    return get_s(n - 1, s + "1" + reversed);
  }
  char findKthBit(int n, int k) {
    string s = "0";
    string ans = get_s(n - 1, s);
    // cout<<ans<<endl;
    return ans[k - 1];
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
