class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pr) {
        unordered_map<int,vector<int>> mp;
        unordered_set<int> st;
        for (auto x: pr) {
            int u = x[0], v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> ans;
        int start = -1;
        for (auto x: mp) {
            if(x.second.size() == 1) {
                start = x.first;
            }
        }
        assert(start != -1);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            st.insert(u);
            ans.push_back(u);
            for (auto v: mp[u]) {
                if(st.count(v) == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};