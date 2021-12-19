#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
struct Node {
  int x;
  Node *next = nullptr;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Node *n = new Node();
  Node *n2 = new Node();
  n2->x = 30;
  n->next = n2;
  n = n->next;
  cout << n->x << endl;
  vector<int> arr;
  arr = vector<int> (10);
  cout<<arr.size()<<endl;
  return 0;
}
