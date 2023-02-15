class Solution {
public:
    bool checkValidString(string s) {
        
        int dp[105][105];
        memset(dp, -1, sizeof(dp));
        
        std::function<int(int,int)> check;
        check = [&](int idx, int cnt) {
            if(idx == s.length()) {
                return int(cnt == 0);
            }
            if(cnt < 0) {
                return 0;
            }
            if(dp[idx][cnt] != -1) {
                return dp[idx][cnt];
            }
            if(s[idx] == '*') {
                return dp[idx][cnt] = (check(idx + 1, cnt - 1) or check(idx + 1, cnt + 1) or check(idx + 1, cnt));
            }
            return dp[idx][cnt] = check(idx + 1, cnt + (s[idx] == ')' ? -1: 1));
        };
        
        return check(0, 0);
    }
};