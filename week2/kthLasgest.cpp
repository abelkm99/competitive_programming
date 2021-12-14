#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

bool comparision(string &a, string &b) {
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }
  return a < b;
}
string kthLargestNumber(vector<string> &arr, int k) {
  sort(arr.rbegin(), arr.rend(), comparision);
  for (string x : arr)
    cout << x << endl;
  return arr[k-1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<string> arr = {"3","6","7","10"};
  cout<<kthLargestNumber(arr, 4)<<endl;
  return 0;
}
