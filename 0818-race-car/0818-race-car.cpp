class Solution {
public:
    int dp[10001];
    int solve(int target) {
        if(dp[target] > 0) {
            return dp[target];
        }
        int n = floor(log2(target)) + 1;
        if((1 << n) - 1 == target) { 
            return dp[target] = n;
        }
        int ans = n + 1 + solve(((1 << n) - 1) - target);
        for(int m = 0; m < n - 1; m++) {
            ans = min(ans, n - 1 + 1 + m + 1 + solve(target - (((1 << (n - 1)) - 1) - ((1 << m) - 1))));
        }
        return dp[target] = ans;
    }

    int racecar(int target) {
        memset(dp, -1, sizeof(dp));
        return solve(target);
    }
};