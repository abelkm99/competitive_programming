class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> counter(10, 0);
        while(n) {
            counter[n % 10]++;
            n /= 10;
        }
        for (int i = 0; (1LL << i) < INT_MAX; i++) {
            vector<int> temp = counter;
            int num = (1 << i);
            while(num) {
                temp[num % 10]--;
                num /= 10;
            }
            bool ok = true;
            for (int freq: temp) {
                ok &= (freq == 0);
            }
            if(ok) {
                return true;
            }
        }
        return false;
    }
};