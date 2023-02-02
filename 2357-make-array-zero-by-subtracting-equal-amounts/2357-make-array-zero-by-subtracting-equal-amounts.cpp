class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while(accumulate(nums.begin(), nums.end(), 0)) {
            cnt++;
            int mn = INT_MAX;
            for (auto x: nums) {
                if(x) {
                    mn = min(x, mn);
                }
            }
            for (auto &x: nums) {
                if(x) {
                    x -= mn;
                }
            }
        }
        return cnt;
    }
};