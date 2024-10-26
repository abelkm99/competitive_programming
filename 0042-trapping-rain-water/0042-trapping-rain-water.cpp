class Solution {
public:
    int trap(vector<int>& arr) {
        vector<int> stack; // monotonic decreasing
        
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(!stack.empty() and arr[stack.back()] < arr[i]) {
                int mid = stack.back();
                // cout << "pop " << mid << " " << arr[mid]<< endl;
                stack.pop_back();
                if(!stack.empty()) {
                    ans += (min(arr[stack.back()], arr[i]) - arr[mid]) * (i - stack.back() - 1);
                }
            }    
            stack.push_back(i);
        }
        return ans;
    }
};