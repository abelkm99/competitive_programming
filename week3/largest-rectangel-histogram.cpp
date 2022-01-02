#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*


        2 1 5 6 2 3

        1 2 3 1

        0 1 2    3

        diffrence to the left and diffrence to the right;

        1+1-1 = 1;
        2+1-1 = 2;



 * */
int largestRectangleArea(vector<int> &arr) {
  stack<int> s;
  int i = 0;
  int max_area = 0;
  while (i < arr.size()) {
    cout << i << "================" << endl;
    if (s.empty() || arr[s.top()] <= arr[i]) {
      s.push(i);
    } else {
      cout << "bout to pop inumber before " << arr[i] << endl;
      // check why is it popped so;
      while (!s.empty() && arr[s.top()] > arr[i]) {
        int t = s.top();
        s.pop();
        int l = -1;
        if (!s.empty())
          l = s.top();
        int diff_l = t - l;
        int diff_r = i - t;
        cout << "poped " << arr[t] << " and the distance is "
             << diff_r + diff_l - 1 << endl;
        int temp_area = (diff_l + diff_r - 1) * arr[t];
        if (temp_area > max_area)
          max_area = temp_area;
      }
      cout << "area is " << max_area << endl;
      s.push(i);
    }
    i++;
  }
  int sum = 0;
  while (!s.empty()) {
    int t = s.top();
    s.pop();
    int l = -1;
    if (!s.empty())
      l = s.top();
    max_area = max(max_area, (abs(t - l) + sum) * arr[t]);
    cout << t - l + sum << endl;
    sum += t - l;
  }
  return max_area;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {2, 1, 5, 6, 2, 3};
  cout << largestRectangleArea(arr) << endl;
  return 0;
}
