#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    bool ans = true;
    vector<int> memo(pushed.size(), 0);
    int pop = 0;
    int push = 1;
    while (pop < popped.size()) {
      if (popped[pop] == pushed[push - 1]) {
        pop++;
        if (push - 1 > 0) {
          memo[push - 1] = 1;
          while (push >= 0 && memo[push - 1] == 1) {
            push--;
          }
        }

      } else {
        // cout<<"searching for "<<popped[pop]<<endl;
        while (push - 1 <= pushed.size() - 1) {
          if (pushed[push - 1] == popped[pop] && memo[push - 1] == 0) {
            break;
          }
          push++;
        }
        // cout<<"push ts "<<push-1<<endl;
        if (push - 1 >= pushed.size()) {
          return false;
        }
        if (pushed[push - 1] != popped[pop]) {
          return false;
        }
        // cout<<"got at  "<<pushed[push-1]<<" "<<push-1<<endl;

        // cout<<"reached here "<<endl;
      }
    }

    return true;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
