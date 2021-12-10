#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  s = "Myself2 Me1 I4 and3";
  vector<pair<int, string>> vs;
  string temp = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      continue;
    } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      temp += s[i];
    } else if (s[i] >= '0' && s[i] <= '9') {
      vs.push_back({s[i] - '0', temp});
      temp = "";
    }
  }
  sort(vs.begin(), vs.end());
  string answer = "";
  for (auto it = vs.begin(); it != vs.end(); it++) {
    answer += it->second;
    answer += " ";
  }
  answer.pop_back();
  cout << answer << endl;
  return 0;
}
