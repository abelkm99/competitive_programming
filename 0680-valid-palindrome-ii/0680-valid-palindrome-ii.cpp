class Solution {
public:
bool solve(string s , int a, int l){
    while(a<l){
     if(s[a]==s[l]){
         a++;
         l--;
         
      }
    else {
         return false;
       }
    }
    return true;
}
    bool validPalindrome(string s) {
        int n = s.length();
       int a = 0;
       int l = n-1;
       //int f=0;
       while(a<l){
          if(s[a]==s[l]){
              a++; l--;
          }
          else return (solve(s,a+1,l) || solve(s,a,l-1));
       }
       
       return true;

    }
};