class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000][1000];
        memset(dp, 0, sizeof(dp));
        int n = s.size();
        string ans = "";
        for(int r = 0; r < n; r++) {
            string temp = "";
            for (int l = r; l >= 0; l--) {
                temp += s[l];
                if(s[l] == s[r]) {
                  if(l+1 >= r) {
                      dp[r][l] = 1;
                  }else{
                      dp[r][l] = dp[r-1][l+1];
                  }
                }
                if(dp[r][l]) {
                    if(r - l + 1 > ans.length()) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};