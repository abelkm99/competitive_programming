class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        int cnt = count(nums.begin(), nums.end(), 0);
        while(l < nums.size() and r < nums.size()) {
            if(nums[l] == 0) {
                while(r < nums.size() and nums[r] == 0) {
                    r++;
                }
                if(r < nums.size()) {
                    swap(nums[l], nums[r]);   
                }
            }
            l++;
            r++;
        }
        for (int i = nums.size() - cnt; i < nums.size(); i++) nums[i] = 0;
    }
};