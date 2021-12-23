#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void merge(vector<int> &arr, int p1, int p2, int p1_max, int p2_max) {
  vector<int> temp;
  int start = p1;
  // cout << "------------starting merge----------" << endl;
  // cout << p1 << " " << p1_max << " " << p2 << " " << p2_max << endl;
  while (p1 < p1_max && p2 < p2_max) {
    if (arr[p1] < arr[p2]) {
      temp.push_back(arr[p1]);
      p1++;
    } else if (arr[p1] >= arr[p2]) {
      temp.push_back(arr[p2]);
      p2++;
    }
  }
  while (p1 < p1_max) {
    temp.push_back(arr[p1]);
    p1++;
  }
  while (p2 < p2_max) {
    temp.push_back(arr[p2]);
    p2++;
  }
  for (int i = 0; i < temp.size(); i++) {
    // cout << temp[i] << endl;
    arr[start] = temp[i];
    start++;
  }

  // for (int x : arr)
  // cout << x << " ";
  // cout << "\n";
  // cout << "------------ending merge----------" << endl;
}
void mergeSort(vector<int> &arr, int l, int r) {
  if (r - l <= 1) {
    return;
  }
  int mid = l + (r - l) / 2;
  // cout << l << " " << mid << " " << r << endl;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid, r);
  merge(arr, l, mid, mid, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  mergeSort(arr, 0, arr.size());
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
