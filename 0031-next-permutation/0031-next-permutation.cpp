class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        auto left = is_sorted_until(nums.rbegin(), nums.rend());
        if(left == nums.rend()) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        // int idx = nums.size() - (left - nums.rbegin());
        auto it = upper_bound(nums.rbegin(), left, *left);
        iter_swap(left, it);
        // std::reverse(nums.begin() + idx, nums.end());
        reverse(left.base(), nums.end());
        
    }
};