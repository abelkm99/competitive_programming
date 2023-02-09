class Solution {
public:
    vector<string> restoreIpAddresses(string ip) {
        vector<string> ans;

    string possible = "";
    std::function<void(int,int)> DFS;

    DFS = [&](int dots, int idx) {
        if(dots == 3 and idx == ip.size()){
            // cout << possible << endl;
            vector<string> local;
            string temp = "";
            for(auto x: possible) {
                if(x == '.') {
                    if(temp.length() >= 1) {
                      local.push_back(temp);
                    }
                    temp = "";
                    continue;
                }
                temp += x;
            }
            if(temp.length()) {
              local.push_back(temp);
            }
            if(local.size() != 4) {
              return;
            }
            bool valid = true;
            for(auto x: local) {
                if(x.empty()) {
                    valid = false;
                    break;
                }
                if( x.size() > 1 and  x[0] == '0') {
                    valid = false;
                    break;
                }
                auto number = stol(x);
                if( number > 255 or number < 0 ){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ans.push_back(possible);
            }
            return;
        }
        if(dots > 3 or idx >= ip.size()) {
            return;
        }
        possible += ".";
        DFS(dots+1, idx);
        possible.pop_back();
        
        possible += ip[idx];
        DFS(dots, idx + 1);
        possible.pop_back();
    };

    DFS(0,0);

    return ans;

    }
};