#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class MyQueue {
  stack<int> s;
  queue<int> q;

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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  MyQueue *obj = new MyQueue();
  cout << obj->empty() << endl;
  obj->push(10);
  obj->push(11);
  // cout << obj->peek() << endl;
  // cout << obj->pop() << endl;
  // cout << obj->peek() << endl;
  // cout << obj->empty() << endl;
  return 0;
}
