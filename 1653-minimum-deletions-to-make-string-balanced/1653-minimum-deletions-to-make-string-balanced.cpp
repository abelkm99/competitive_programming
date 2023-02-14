class Solution {
public:
    int minimumDeletions(string s) {
        // from the left how many 
        // remove all the values of bs so far a
        int ta = count(s.begin(), s.end(), 'a');
        
        int la = 0;
        int cost = INT_MAX;
        for (int i = 0; i <= s.length(); i++) {
            int lb = i - la;
            int ra = ta - la;
            // cout << i << " " << lb << " " << ra << endl;
            cost = min(cost, lb + ra);
            if(i == s.length()) {
                break;
            }
            if(s[i] == 'a') {
                la++;
            }
        }
        return cost;
    }
};