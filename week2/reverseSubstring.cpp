#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
string reverseParenthesis(string s) {
  stack<char> st;
  for (char c : s) {
    if (c != ')') {
      st.push(c);
    } else {
      string temp = "";
      while (!st.empty() && st.top() != '(') {
        temp += st.top();
        st.pop();
      }
      st.pop();
      for (auto x : temp)
        st.push(x);
    }
  }
  string ans;
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s = "(u(love)i)";
  cout<<reverseParenthesis(s)<<endl;
  return 0;
}
