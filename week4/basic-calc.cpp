#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void print(deque<int> nums) {
  while (!nums.empty()) {
    cout << nums.front() << " ";
    nums.pop_front();
  }
  cout << "\n";
}
class Solution {
public:
  int operation(int a, int b, char c) {
    if (c == '+')
      return a + b;
    if (c == '-')
      return a - b;
    if (c == '*')
      return a * b;
    return a / b;
  }
  int calculate(string arr) {
    deque<char> op1;
    deque<char> op2;
    deque<int> nums;
    string temp = "";
    bool waiting = false;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == ' ') {
        continue;
      }
      if (arr[i] >= '0' && arr[i] <= '9') {
        temp += arr[i];
      } else {
        double n = stoi(temp);
        nums.push_back(n);
        if (waiting) {
          int a = nums.back();
          nums.pop_back();
          int b = nums.back();
          nums.pop_back();
          char c = op1.back();
          int res = operation(b, a, c);
          // cout<<a<<c<<b<<"="<<res<<endl;
          nums.push_back(res);
          waiting = false;
          op1.pop_back();
        }
        if (arr[i] == '*' || arr[i] == '/') {
          op1.push_back(arr[i]);
          waiting = true;
        } else {
          op2.push_back(arr[i]);
        }
        temp = "";
      }
    }
    int n = stoi(temp);
    nums.push_back(n);
    if (waiting) {
      int a = nums.back();
      nums.pop_back();
      int b = nums.back();
      nums.pop_back();
      char c = op1.back();
      int res = operation(b, a, c);
      // cout<<a<<c<<b<<"="<<res<<endl;
      nums.push_back(res);
      waiting = false;
      op1.pop_back();
    }
    // print(nums);

    int a, b, val;
    char c;
    while (!op2.empty()) {
      a = nums.front();
      nums.pop_front();
      b = nums.front();
      nums.pop_front();
      c = op2.front();
      op2.pop_front();
      val = operation(a, b, c);
      // cout << a << c << b << "=" << val << endl;
      nums.push_front(val);
    }
    return val;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s = "1*2-3/4+5*6-7*8+9/10";
  s = " 3/2 ";
  // cin >> s;

  Solution *ans = new Solution;
  cout << ans->calculate(s) << endl;
  return 0;
}
