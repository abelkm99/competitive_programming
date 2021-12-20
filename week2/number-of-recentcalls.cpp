#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class RecentCounter {
  vector<int> arr;
  int last_index = 0;

public:
  RecentCounter() {}

  int ping(int t) {
    int min_range = max(0, t - 3000);
    arr.push_back(t);
    // cout<<min_range<<"-->"<<t<<"size of array is "<<arr.size()<<endl;

    while (arr[last_index] < min_range) {
      last_index++;
    }

    return arr.size() - last_index;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  RecentCounter *r = new RecentCounter();
  cout << r->ping(100) << '\n';
  cout << r->ping(110) << '\n';
  cout << r->ping(3000) << '\n';
  cout << r->ping(4000) << '\n';
  cout << r->ping(5000) << '\n';
  cout << r->ping(6000) << '\n';
  return 0;
}
