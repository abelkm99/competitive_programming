#define all(a) a.begin(), a.end()
using pi = pair<int,int>;
using max_heap = priority_queue<int,vector<int>,greater<int>>;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pi> vp;
        for (int i = 0; i < scores.size(); i++) {
            vp.push_back({scores[i], ages[i]});
        }
        vp.push_back({0,0});
        sort(vp.begin(), vp.end(), [](auto &a, auto &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        // int for every index get the answer from the previous
        int dp[1001];
        dp[0] = 0;
        int ans = 0;
        for (int i = 1; i < vp.size(); i++) {
            dp[i] = 0;
            for (int j = i-1; j >=0; j--) {
                if(vp[i].first >= vp[j].first) {
                    dp[i] = max(dp[i], dp[j] + vp[i].first);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};