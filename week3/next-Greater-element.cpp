#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1,vector<int> &nums2){
	vector<int> ans;
	stack<int> s;
	unordered_map<int,int> mp;
	for(int i=0;i<nums2.size();i++){
		if(!s.empty() && s.top()<nums2[i]){
			while(!s.empty() && s.top()<nums2[i]){
				mp[s.top()] = nums2[i];
				s.pop();
			}
			s.push(nums2[i]);
		}
		else{
			s.push(nums2[i]);
		}
	}
	while(!s.empty()){
		mp[s.top()] = -1;
		s.pop();
	}
	for(int i=0;i<nums1.size();i++){
		ans.push_back(mp[nums1[i]]);
	}
	return ans;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   vector<int> nums1 = {2,4};
   vector<int> nums2 = {1,2,3,4};
   vector<int> ans = nextGreaterElement(nums1,nums2);
   for(int x:ans) cout<<x<<" ";
   cout<<endl;
   return 0;
}
