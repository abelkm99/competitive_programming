#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  string removeKdigits(string num, int k) {
    if (k >= num.length())
      return "0";
    stack<char> s;
    int i = 0;
    while (i < num.length()) {
      while (k && !s.empty() && s.top() > num[i]) {
        k--;
        s.pop();
      }
      s.push(num[i]);
      i++;
    }
    while (k && !s.empty()) {
      s.pop();
      k--;
    }
    string ans = "";
    while (!s.empty()) {
      ans += s.top();
      s.pop();
    }
    while (ans.length() && ans.back() == '0') {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    if (ans.length()) {
      return ans;
    }
    return "0";
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
