class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int W) {
        // what should i do
        // how many words can i add
        // if it were the last one
        // how many
        // justify center means
        
        vector<string> ans;
        auto justify_center = [&](int start, int end) {
            // get the total words count
            int total = 0;
            
            // get the cnt 
            int cnt = end - start + 1;
            if(cnt == 1) {
                string temp_ans = words[start];
                int rem = W - temp_ans.length();
                while(rem--) {
                    temp_ans += " ";
                }
                ans.push_back(temp_ans);
                return;
            }
            for (int i = start; i <= end; i++) {
                total += words[i].size();
            }
            // how mang gaps can i create
            int V = (W - total) / (cnt-1);
            int rem = (W - total) % (cnt-1);
            string space = "";
            while(V--) {
                space += " ";
            }
            
            string temp_ans = "";
            int p1 = start;
            int p2 = 0;
            int round = 0;
            while(p1 <= end) {
                if(round % 2 == 0) {
                    temp_ans += words[p1];
                    p1++;
                }
                else {
                    temp_ans += space;
                    if(--rem >= 0) {
                        
                        temp_ans += " ";
                    }
                    p2++;
                }
                round++;
            }
            ans.push_back(temp_ans);
        };
        int i = 0;
        while(i < words.size()) {
            int j = i;
            int total = 0;
            while(j < words.size() and total + words[j].size() <= W) {
                total += words[j].size() + 1;
                j++;
            }
            if(j == words.size()) {
                string temp_ans = "";
                while(i < words.size()) {
                    temp_ans += words[i];
                    temp_ans += " ";
                    i++;
                }
                temp_ans.pop_back();
                int rem = W - temp_ans.size();
                while(rem--) {
                    temp_ans += " ";
                }
                ans.push_back(temp_ans);
                continue;
            }
            justify_center(i, j-1);
            i = j;
        }
        return ans;
    }
};