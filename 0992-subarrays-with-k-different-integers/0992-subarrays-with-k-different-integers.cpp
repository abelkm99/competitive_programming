class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        /*
        
          so given an array
            a sub array s is called good if it has exactly k number of different numbers
            
            //
            
            ------------
            |          |
        */
        using pi = pair<int,int>;
        using vpi = vector<pi>;
        unordered_map<int,int> mp;
        unordered_map<int,int> latest_pos;
        priority_queue<pi,vpi,greater<pi>> min_heap;
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0;
        while(r < n) {
            mp[nums[r]]++;
            latest_pos[nums[r]] = r;
            min_heap.push({r, nums[r]});
            r++;
            while(mp.size() > k) {
                auto it = mp.find(nums[l]);
                it->second -= 1;
                if(it->second == 0) {
                   mp.erase(it);
                   latest_pos[nums[l]] = -1;
                }
                l++;
            }
            if(mp.size() == k) {
                while(!min_heap.empty() and latest_pos[min_heap.top().second] != min_heap.top().first) {
                    min_heap.pop();
                }
//                cout << min_heap.top().first  << " - " << l << " + 1" << endl;
                ans += (min_heap.top().first - l + 1);
            } 
        }
        
        return ans;
        
    }
};