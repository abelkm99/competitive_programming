class DetectSquares {
public:
    int dp[1001][1001];
    DetectSquares() {
        memset(dp, 0, sizeof(dp));
    }
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        dp[x][y]++;
    }
    
    int count(vector<int> point) {
        // if he current point was at 0,1
        int x = point[0], y = point[1];
        int cnt = 0;
        for (int i = 0; i <= 1000; i++) {
            if(i == x) {
                continue;
            }
            int diff = abs(x - i);
            if(dp[i][y]) {
                // check to the top and to the bottom
                if(y+diff >= 0 and y + diff <= 1000) {
                    cnt += (dp[i][y] * dp[i][y+diff] * dp[x][y+diff]);
                }
                if(y - diff >= 0 and y - diff <= 1000) {
                    cnt += (dp[i][y] * dp[i][y-diff] * dp[x][y-diff]);
                }
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */