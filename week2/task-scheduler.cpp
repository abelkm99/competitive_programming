#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
struct Node {
  int c;
  int remaining;
  int last_check = -1;
};
/*
  aaabbb
  a->2
  b->2

  3,3
  2,2
  aaabbbcccddee
  33321

  33221
  32221
  22221
  22211
  22111
  21111
  11111
  11110
  11100
  11000
  10000
  00000

  5311
  4200
  4200
*/

void print_pq(priority_queue<pair<int, int>> pq) {
  while (!pq.empty()) {
    cout << pq.top().first << " ";
    pq.pop();
  }
  cout << '\n';
}
int solution_3(vector<char> &tasks, int n) {

  priority_queue<pair<int, int>> pq;
  vector<int> memo(26, 0);
  for (char c : tasks) {
    memo[c - 'A']++;
  }

  for (int x : memo) {
    if (x != 0)
      pq.push({x, -1});
  }
  int counter = 0;
  cout << "here\n";
  while (!pq.empty() && pq.top().first != 0) {
    cout << counter << endl;
    print_pq(pq);
    vector<pair<int, int>> temp;
    int val = n + 1;
    int time = 0;
    while (val-- && !pq.empty()) {
      pair<int, int> pr = pq.top();
      pq.pop();
      pr.first = pr.first - 1;
      pr.second = counter;
      if (pr.first)
        temp.push_back(pr);
      time++;
    }
    for (auto x : temp)
      pq.push(x);
    if (!pq.empty()) {
      counter += n + 1;
    } else {
      counter += time;
    }
  }
  return counter;
}
int solution_2(vector<char> &tasks, int n) {

  priority_queue<pair<int, int>> pq;
  vector<int> memo(26, 0);
  for (char c : tasks) {
    memo[c - 'A']++;
  }

  for (int x : memo) {
    if (x != 0)
      pq.push({x, -1});
  }
  int counter = 0;
  while (!pq.empty() && pq.top().first != 0) {
    // check if the top can do the job
    print_pq(pq);
    if (counter - pq.top().second > n || pq.top().second == -1) {
      auto pr = pq.top();
      pq.pop();
      pr.first -= 1;
      pr.second = counter;
      pq.push(pr);
      counter++;
      continue;
    }
    // which tasks can be done if we can't do a;
    vector<pair<int, int>> temp_arr;
    bool updated = false;
    while (!pq.empty() && pq.top().first != 0) {
      if (counter - pq.top().second > n || pq.top().second == -1) {
        auto pr = pq.top();
        pq.pop();
        pr.first = pr.first - 1;
        pr.second = counter;
        pq.push(pr);
        counter++;
        updated = true;
        break;
      } else {
        temp_arr.push_back(pq.top());
        pq.pop();
      }
    }
    // cout << pq.size() << endl;
    // break;
    for (auto x : temp_arr)
      pq.push(x);
    if (!updated) {
      counter++;
    }
    // check for a value in the que that can do the task;
  }

  return counter;
}
int leastInterval(vector<char> &tasks, int n) {
  vector<Node> arr;
  vector<int> memo(26, 0);
  for (char c : tasks) {
    memo[c - 'A']++;
  }

  for (int i = 0; i < memo.size(); i++) {
    if (memo[i]) {
      Node *n = new Node();
      n->c = memo[i];
      n->remaining = memo[i];
      n->last_check = -1;
      arr.push_back(*n);
    }
  }
  int counter = 0;
  while (true) {
    bool do_task = false;
    bool is_remaing_task = false;
    for (auto &x : arr) {
      // cout << x.c << " " << x.remaining << endl;
      if (x.remaining)
        is_remaing_task = true;
      if (x.remaining && (x.last_check == -1 || counter - x.last_check > n)) {
        // cout << (counter - x.last_check > n) << endl;
        cout << x.c << endl;
        x.remaining = x.remaining - 1;
        x.last_check = counter;
        break;
      }
    }
    if (do_task == false && is_remaing_task == false) {
      break;
    }
    counter++;
  }
  return counter;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B',
  //                       'C', 'C', 'C', 'D', 'D', 'E'};
  vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A',
                        'B', 'C', 'D', 'E', 'F', 'G'};
  // vector<char> tasks = {'A', 'B', 'C', 'A'};
  int n = 2;
  cout << solution_3(tasks, n) << endl;
  return 0;
}
