class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (string &s: logs) {
            if(s == "../") {
                cnt = max(0, --cnt);
                continue;
            }
            if(s == "./") {
                continue;
            }
            cnt++;
        }
        return cnt;
    }
};