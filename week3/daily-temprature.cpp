#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int> dailyTempratures(vector<int> &arr){
	vector<int> ans(arr.size(),0);
	stack<pair<int,int>> s;
	for(int i=0;i<arr.size();i++){
		if(!s.empty() && s.top().first<arr[i]){
			while(!s.empty() && s.top().first<arr[i]){
				pair<int,int> pr = s.top();
				ans[pr.second] = i - pr.second;
				s.pop();
			}
			s.push({arr[i],i});
		}else{
			s.push({arr[i],i});
		}
	}
	return ans;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   vector<int> arr = {30,40,50,60};
   vector<int> ans = dailyTempratures(arr);
   for(int x:ans) cout<<x<<" ";
   cout<<endl;
   return 0;
}
