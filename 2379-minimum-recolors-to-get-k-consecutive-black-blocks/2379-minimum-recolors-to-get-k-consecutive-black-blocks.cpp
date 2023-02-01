class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0, b = 0;
        int ans = k;
        for (int i = 0; i < k; i++) {
            if(blocks[i] == 'W') w++;
            else b++;
        }
        ans = min(ans, k - b);
        for (int i = k; i < blocks.size(); i++) {
            if(blocks[i] == 'W') w++;
            else b++;
            if(blocks[i - k] == 'W') w--;
            else b--;
            ans = min(ans, k - b);
        }
        return ans;
    }
};