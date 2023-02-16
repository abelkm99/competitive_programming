class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prev = max(nums[i], prev + nums[i]);
            ans = max(ans, prev);
        }
        
        return ans;
    }
};