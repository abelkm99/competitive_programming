class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            pww
        */
        // if(s.length()==0) return 0;
        int l = 0;
        int r = 0;
        vector<int> arr(250,0);
        int ans = 0;
        while(r<s.length()){
            if(arr[s[r]]>0){
                while(s[l]!=s[r]){
                    arr[s[l]]--;
                    l++;
                }
                arr[s[l]]--;
                l++;
                arr[s[r]]++;
            }else{
                arr[s[r]]++;
            }
            // cout<<l<<" "<<r<<endl;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};