#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int operation(int a,int b,string c){
	if(c=="+") return a+b;
	if(c=="-") return a-b;
	if(c=="*") return a*b;
	if(c=="/") return a/b;
	return 0;
}
int evalRPN(vector<string> &tokens){
	stack<int> s;
	for(string x:tokens){
		if(x=="+"||x=="-"||x=="*"||x=="/){
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			s.push(operation(b,a,x));
		}else{
			s.push(stoi(x));
		}
	}

	return s.top();
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   return 0;
}
