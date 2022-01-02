#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int v_sum(vector<int> &arr) {
  int s = 0;
  for (int x : arr)
    s += x;
  return s;
}
bool are_equal(priority_queue<pair<int, stack<int>>> pq) {
  vector<int> check(3, 0);
  int i = 0;
  while (!pq.empty()) {
    check[i] = pq.top().first;
    pq.pop();
    i++;
  }
  return ((check[0] == check[1]) && (check[1] == check[2]));
}
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
  int s = 0;
  map<int, int> mp;
  int mx = 0;
  cout << "-------------\n";
  for (int i = h1.size() - 1; i >= 0; i--) {
    s += h1[i];
    cout << s << endl;
    if (mp[s]) {
      mp[s]++;
    } else {
      mp[s] = 1;
    }
  }
  cout << "-------------\n";
  s = 0;
  for (int i = h2.size() - 1; i >= 0; i--) {
    s += h2[i];
    cout << s << endl;
    if (mp[s]) {
      mp[s]++;
    } else {
      mp[s] = 1;
    }
  }
  cout << "-------------\n";
  s = 0;
  for (int i = h3.size() - 1; i >= 0; i--) {
    s += h3[i];
    cout << s << endl;
    if (mp[s]) {
      mp[s]++;
    } else {
      mp[s] = 1;
    }
  }
  int ans = 0;
  for (auto x : mp) {
    if (x.second == 3) {
      cout << x.first << endl;
      ans = max(ans, x.first);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<int> h1(n1);
  vector<int> h2(n2);
  vector<int> h3(n3);
  for (auto &x : h1)
    cin >> x;
  for (auto &x : h2)
    cin >> x;
  for (auto &x : h3)
    cin >> x;
  cout << equalStacks(h1, h2, h3) << endl;
  return 0;
}
