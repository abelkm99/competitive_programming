class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<int> arr(26,0);
        for(auto c:s1){
            arr[c-'a']++;
        }
        for(auto c:s2){
            arr[c-'a']++;
        }
        for(auto c:s3){
            arr[c-'a']--;
            if(arr[c-'a']<0){
                return false;
            }
        }
        int sm = accumulate(arr.begin(),arr.end(),0);
        return !sm?true:false;
    }
};