#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
  232
  a b c
  a -> ad, ae, af
  b -> bd, be, bf
  c -> cd, ce, cf

  ad -> ada adb adc
  ae -> ada adb adc

  number = 23

  permutation(ans,temp,index):
    if(index>number.length()){
      ans.append(temp);
    }
    for i in number[index];
      permutation(temp+=i,index+1)
*/
void permutation(string digits, int index, string temp, map<char, string> &m,
                 vector<string> &ans) {
  if (temp.length() == digits.length()) {
    ans.push_back(temp);
    return;
  }
  string vals = m[digits[index]];
  for (char c : vals) {
    temp += c;
    permutation(digits, index + 1, temp, m, ans);
    temp.pop_back();
  }
}
vector<string> letterCombinations(string digits) {
  vector<string> ans;
  if (digits.length() == 0)
    return ans;
  map<char, string> phone;
  phone['2'] = "abc";
  phone['3'] = "def";
  phone['4'] = "ghi";
  phone['5'] = "jkl";
  phone['6'] = "mno";
  phone['7'] = "pqrs";
  phone['8'] = "tuv";
  phone['9'] = "xyz";
  permutation(digits, 0, "", phone, ans);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string digits = "2345";
  vector<string> ans = letterCombinations(digits);
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
