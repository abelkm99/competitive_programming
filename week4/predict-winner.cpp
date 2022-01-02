#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
struct Node {
  int p1;
  int p2;
  int range;
};
void prediction(vector<int> &nums, int turn, int score_p1, int score_p2, int l,
                int r, bool &ans, vector<Node> &result) {
  // cout << "======================================\n";
  // cout << score_p1 << " " << score_p2 << endl;
  if (l > r) {
    // if (score_p1 < score_p2) {
    //   ans = false;
    // }
    //
    Node *n = new Node;
    n->p1 = score_p1;
    n->p2 = score_p2;
    n->range = abs(score_p1 - score_p2);
    result.push_back(*n);
    return;
  }
  if (l == r) {
    // if (score_p1 + nums[l] >= score_p2) {
    //   ans = true;
    // }
    Node *n = new Node;
    n->p1 = score_p1 + nums[l];
    n->p2 = score_p2;
    n->range = abs(score_p1 + nums[l] - score_p2);
    result.push_back(*n);
    return;
  }

  if (turn % 2) {
    // if (nums[l] > nums[r]) {
    //   cout << "player 2 takes " << nums[l] << endl;
    //   prediction(nums, turn + 1, score_p1, score_p2 + nums[l], l + 1, r,
    //   ans,result);
    // }
    // if (nums[r] > nums[l]) {
    //   cout << "player 2 takes " << nums[r] << endl;
    //   prediction(nums, turn + 1, score_p1, score_p2 + nums[r], l, r - 1,
    //   ans);
    // }
    // if (nums[l] == nums[r]) {
    // cout << "player 2 takes " << nums[l] << endl;
    prediction(nums, turn + 1, score_p1, score_p2 + nums[l], l + 1, r, ans,
               result);
    // cout << "player 2 takes " << nums[r] << endl;
    prediction(nums, turn + 1, score_p1, score_p2 + nums[r], l, r - 1, ans,
               result);
    // }
    // if (ans)
    // return;

  } else {
    /*
    if(nums[l]>nums[r]){
            cout<<"player 1 takes "<<nums[l]<<endl;
            prediction(nums,turn+1,score_p1+nums[l],score_p2,l+1,r,ans);
    }
    if(nums[r]>nums[l]){
            cout<<"player 1 takes "<<nums[r]<<endl;
            prediction(nums,turn+1,score_p1+nums[r],score_p2,l,r-1,ans);
    }
    if(nums[l] == nums[r]){
            */
    // cout << "player 1 takes " << nums[l] << endl;
    prediction(nums, turn + 1, score_p1 + nums[l], score_p2, l + 1, r, ans,
               result);
    // cout << "player 1 takes " << nums[r] << endl;
    prediction(nums, turn + 1, score_p1 + nums[r], score_p2, l, r - 1, ans,
               result);
    //}
    // if (ans)
    //   return;
    return;
  }
}
bool custome_sort(Node const &n1, Node const &n2) { return n1.p1 > n2.p1; }
int solve(vector<int> &nums, int l, int r) {
  if (l == r)
    return nums[l];
  if (l > r)
    return 0;
  int left = nums[l] - solve(nums, l + 1, r);
  int right = nums[r] - solve(nums, l, r - 1);
  return max(left, right);
}
bool PredictTheWinner(vector<int> &nums) {
  int ans = solve(nums, 0, nums.size() - 1);
  return ans >= 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 5, 233, 7};
  bool ans = PredictTheWinner(nums);
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
