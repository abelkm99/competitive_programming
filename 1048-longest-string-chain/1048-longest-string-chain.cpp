class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](auto &a, auto &b) {
           return a.length() < b.length(); 
        });
        int n = words.size();
        vector<int> dp(n, 1);
        
        auto check = [&](string &s1, string &s2) -> bool {
            if(s2.length() - s1.length() != 1) return false;
            int j = 0, i = 0;
            while(i < s1.length()) {
                while(j < s2.length() and s1[i] != s2[j]) {
                    j++;
                }
                if(j >= s2.length()) return false;
                j++;
                i++;
            }
            return true;
        };
        string w1 = "aae";
        string w2 = "eaef";
        
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if(check(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    cout << words[j] << " " << words[i] << " " << dp[i] << endl;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};