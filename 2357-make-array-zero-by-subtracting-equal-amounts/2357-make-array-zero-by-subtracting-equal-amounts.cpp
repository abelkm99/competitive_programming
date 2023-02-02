class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        while(nums.size() and nums.back() == 0) {
            nums.pop_back();
        }
        reverse(nums.begin(), nums.end());
        
        int sm = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] - sm > 0) {
                // means i can also contribute
                nums[i] -= sm;
                sm += nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};