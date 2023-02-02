class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> digits;
        vector<pair<string, string>> letters;
        for (auto s: logs) {
            string temp = "";
            int i = 0;
            while(s[i] != ' ') {
                temp += s[i];
                i++;
            }
            
            if(s[i+1] >= '0' and s[i+1] <= '9') {
                digits.push_back(s);
            }
            else{
                letters.push_back({s.substr(temp.size()+1,s.size()), temp});
            }
        }
        
        sort(letters.begin(), letters.end(), [](auto a, auto b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
            }
        );
        vector<string> ans;
        for (auto x: letters) {
            ans.push_back(x.second+" "+x.first);
        }
        for (auto x: digits) {
            ans.push_back(x);
        }
        return ans;
    }
};