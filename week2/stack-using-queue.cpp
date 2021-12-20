#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class MyQueue {
  stack<int> s;

public:
  MyQueue() {}
  void push(int x) { s.push(x); }
  int pop() {
    stack<int> cp;
    while (!s.empty()) {
      cp.push(s.top());
      s.pop();
    }
    int val = cp.top();
    cp.pop();
    while (!cp.empty()) {
      s.push(cp.top());
      cp.pop();
    }
    return val;
  }
  int peek() {
    stack<int> cp;
    while (!s.empty()) {
      cp.push(s.top());
      s.pop();
    }
    int val = cp.top();
    while (!cp.empty()) {
      s.push(cp.top());
      cp.pop();
    }
    return val;
  }
  bool empty() { return s.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
