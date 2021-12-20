#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
/*
 AAACCCGGCCAAACCC
 
 AAAAACCCCCGGGCCCAAAAACCCCCCAAAAAGGGTTT
 bruetforce technique
 for(int i=0;i<s.lenght()-10;i++){
	for(int j=i+1;j<s.length();j++){
	}
 }
 * */
vector<string> findRepeatedDnaSequences(string s) {
	if(s.length()<10) return {};
	cout<<"here\n";
	unordered_map<string,int> mp;
	for(int i=0;i<=s.length()-10;i++){
		string sub= s.substr(i,10);
		mp[sub]++;
	}
	vector<string> ans;
	for(pair<string,int> x:mp){
		if(x.second>1){
			ans.push_back(x.first);
		}
	}
	return ans; 
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> ans = findRepeatedDnaSequences(s);
  for(string x:ans)cout<<x<<"\n";
  return 0;
}
