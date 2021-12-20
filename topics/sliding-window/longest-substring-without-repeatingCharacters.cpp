#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int legthOfLongestSubstring(string s){
	int len = 0;
	int l = 0;
	int r = 0;
	vector<bool> memo(150,false);
	while(r<s.length()){
		while(!memo[s[r]] && r<s.length()){
			memo[s[r]] = true;
			r++;
		}
		if(r<s.length()){
			len = max(len,r-l);
			memo[s[r]] = false;
			int cp = r;
			while(s[l]!=s[r]){
				memo[s[l]] = false;
				l++;
			}
			l++;
		}
	}
	
	len = max(len,r-l);
	return len;
	
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   string s = "abcabcbb";
   cin>>s;
   cout<<legthOfLongestSubstring(s)<<endl;
   return 0;
}
