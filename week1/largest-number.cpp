#include <bits/stdc++.h>
#include <numeric>
#include <string>
#define ll long long
#define pb push_back
using namespace std;

bool customComarision(const pair<int, string> &a, const pair<int, string> &b) {
  string s1 = a.second + b.second;
  string s2 = b.second + a.second;
  return s1 > s2;
  // int s1_sum = 0;
  // int s2_sum = 0;
  // int len = min(s1.length(), s2.length());
  // cout << s1 << " = " << s1_sum << " --vs-- " << s2 << " = " << s2_sum
  // << endl;
  //   int i = 0;
  //   for (; i < len; i++) {
  //     s1_sum += s1[i] - '0';
  //     s2_sum += s2[i] - '0';
  //     if (s1_sum != s2_sum) {
  //       return s1_sum > s2_sum;
  //     }
  //   }
  //   if (s1_sum == s2_sum) {
  //     if (s1 > s2) {
  //       return s1[i] > s2[i - 1];
  //     } else {
  //       return s1[i - 1] > s2[i];
  //     }
  //   }
  //   return s1_sum > s2_sum;
  // }
}
string remove_zeros(string s, int location) {
  string temp = "";
  for (int i = location; i < s.length(); i++)
    temp += s[i];
  return temp;
}
string largestNumber(vector<int> &arr) {
  vector<pair<int, string>> recorde;
  for (int x : arr) {
    string num = to_string(x);
    int first = (num[0] - '0');
    recorde.push_back({first, num});
  }
  sort(recorde.begin(), recorde.end(), customComarision);
  string ans = "";
  int location = 0;
  bool found = false;
  for (auto it = recorde.begin(); it != recorde.end(); it++) {
    if (it->second != "0") {
      found = true;
    }
    if (!found)
      location++;
    ans += it->second;
  }
  location = max(0, location - 1);
  return remove_zeros(ans, location);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {0, 0};
  cout << largestNumber(arr) << endl;
  return 0;
}
