#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
 	2 3 1 2 4 3     7
	2 5 6 8		len = 4
	  3 4 6 10	len = 4
	    1 3 7    	len = 3
	      2 6 9     len = 3
	      	4 7 	len = 2

 * */

int minSubArrayLen(int target, vector<int> &nums){
	int l = 0;
	int r = 0;
	int total = 0;
	int ans = INT_MAX;
	while(r<nums.size()){
		total+=nums[r];
		// shrink it
		while(total>=target){
			ans = min(ans,r-l+1);
			total-=nums[l];
			l++;
		}
		r++;
	
	}
	if(ans==INT_MAX) ans = 0;
	return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1,1,1,1,1,1,1,1};
  cout<<minSubArrayLen(11,nums)<<endl;
  return 0;
}
