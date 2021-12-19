#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
bool isValid(string s) {
  stack<char> stk;
  for (char c : s) {
    if (c == '(')
      stk.push(c);
    if (c == '[')
      stk.push(c);
    if (c == '{')
      stk.push(c);
    if (c == ')') {
      if (!stk.empty() && stk.top() == '(') {
        stk.pop();
      } else {
        return false;
      }
    }
    if (c == ']') {
      if (!stk.empty() && stk.top() == '[') {
        stk.pop();
      } else {
        return false;
      }
    }
    if (c == '}') {
      if (!stk.empty() && stk.top() == '{') {
        stk.pop();
      } else {
        return false;
      }
    }
  }
  return stk.empty();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s = "()[]{}";
  cout << isValid(s) << endl;
  return 0;
}
