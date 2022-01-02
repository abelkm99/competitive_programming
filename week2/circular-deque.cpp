#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
struct Node {
  int x;
  Node *next = nullptr;
};
class MyCircularDeque {
private:
  vector<int> arr;
  int front;
  int rear;
  int k;
  int space;

public:
  MyCircularDeque(int val) {
    arr = vector<int>(val);
    front = 0;
    rear = val - 1;
    space = val;
    k = val;
  }

  bool insertFront(int value) {
    if (!space) {
      return false;
    }
    arr[front] = value;
    front = (front + 1) % k;
    space--;
    return true;
  }

  bool insertLast(int value) {
    if (!space) {
      return false;
    }
    arr[rear] = value;
    rear = (rear + k - 1) % k;
    space--;
    return true;
  }

  bool deleteFront() {
    if (space == k) {
      return false;
    }
    front = (front + k - 1) % k;
    space++;
    return true;
  }

  bool deleteLast() {
    if (space == k) {
      return false;
    }
    rear = (rear + 1) % k;
    space++;
    return true;
  }

  int getFront() {
    if (space == k) {
      return -1;
    }
    return arr[(front + k - 1) % k];
  }

  int getRear() {
    if (space == k) {
      return -1;
    }
    return arr[(rear + 1) % k];
  }

  bool isEmpty() { return space == k; }

  bool isFull() { return space == 0; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  MyCircularDeque *d = new MyCircularDeque(3);
  // Node *n = new Node();
  // Node *n2 = new Node();
  // n2->x = 30;
  // n->next = n2;
  // n = n->next;
  // cout << n->x << endl;
  // vector<int> arr;
  // arr = vector<int>(10);
  // cout << arr.size() << endl;
  return 0;
}
