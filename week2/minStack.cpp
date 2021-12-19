#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void get_min_index(vector<int> v) {
  int index = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= v[i + 1]) {
      index = i;
    } else {
      index = i + 1;
    }
  }
}
class MinStack {
  stack<int> s;
  vector<int> v;
  int index = INT_MAX;

public:
  void push(int x) {
    v.push_back(x);
    for (int i = 0; i < v.size(); i++) {
      if (v[i] < index)
        index = i;
    }
  }
  void pop() { v.pop_back(); }
  int top() { return v[v.size() - 1]; }
  int getMin() { v[index]; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  MinStack *obj = new MinStack();
  // obj->push(10);
  // obj->pop();
  // int param_3 = obj->top();
  // int param_4 = obj->getMin();
  return 0;
}
