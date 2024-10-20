class Solution {
public:
double get_ans(vector<int> &nums1, vector<int> &nums2, int s1, int s2, int e1,
               int e2) {
  cerr << s1 << " " << s2 << " " << e1 << " " << e2 << endl;
  int n = e1 + e2 - s1 - s2;
  assert(n & 1);
  int target = n / 2;
  int l = -1e6;
  int r = 1e6;

  auto get = [&](int mid) {
    int cnt = 0;
    for (int i = s1; i < e1; i++) {
      int x = nums1[i];
      if (x > mid) {
        break;
      }
      cnt++;
    }
    for (int i = s2; i < e2; i++) {
      int x = nums2[i];
      if (x > mid) {
        break;
      }
      cnt++;
    }
    return cnt;
  };

  while (l <= r) {
    int mid = l + (r - l) / 2;
    // cerr << l << " " << mid << " " << r << endl;
    int ans = get(mid);
    if (ans > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
double calc(vector<int> &arr) {
    int n = arr.size();
    if(n&1) {
        return arr[n/2];
    }
    return (double)(arr[n/2] + arr[(n/2) - 1] ) / 2;
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if(nums1.empty()) {
        return calc(nums2);
    }
    if(nums2.empty()) {
        return calc(nums1);
    }
  int n = nums1.size() + nums2.size();
  if (n % 2 == 0) {
    int s1 = 0;
    int s2 = 0;
    int e1 = nums1.size();
    int e2 = nums2.size();
    if (nums1[0] < nums2[0]) {
      s1++;
    } else {
      s2++;
    }
    double a = get_ans(nums1, nums2, s1, s2, e1, e2);
    s1 = 0;
    s2 = 0;
    if (nums1.back() > nums2.back()) {
      e1--;
    } else {
      e2--;
    }
    double b = get_ans(nums1, nums2, s1, s2, e1, e2);
    return (a + b) / 2;
  }
  return get_ans(nums1, nums2, 0, 0, nums1.size(), nums2.size());
};

};