class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.length();
        int p1 = 0;
        int p2 = n-1;
        while(p1 < p2 and s[p1] == s[p2]) {
            p1++;
            p2--;
        }
        if(p1 >= p2) return true;
        int a = p1;
        int b = p2-1;
        while(a < b and s[a] == s[b]) {
            a++;
            b--;
        }
        if(a >= b) return true;
        a = p1+1;
        b = p2;
        while(a < b and s[a] == s[b]) {
            a++;
            b--;
        }
        if(a >= b) return true;
        return false;
    }
};