class Solution {
public:
    long long numberOfWays(string s) {
        /*
          1 0 1
          0 1 0
          
          
        */
        vector<int> nums;
        for (int i = 0; i < s.size(); i++) {
            nums.push_back(s[i] - '0');
        }
        long long dp[100005][3][3];
        memset(dp, -1, sizeof(dp));
        
        function<long long(int,int,int)> solve;
        
        solve = [&](int idx, int prev, int cnt) {
            if(cnt == 3) {
                return 1LL;
            }
            if(idx == nums.size()) {
                return 0LL;
            }
            if(dp[idx][prev][cnt] != -1) {
                return dp[idx][prev][cnt];
            }
            long long can = 0;
            if(nums[idx] != prev) {
                can = solve(idx+1, nums[idx], cnt+1);
            }
            long long dont = solve(idx+1, prev, cnt);
            return dp[idx][prev][cnt] = can + dont;
        };
        
        return solve(0, 2, 0);
    }
};