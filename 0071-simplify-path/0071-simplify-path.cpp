class Solution {
public:
    string simplifyPath(string path) {
        if(path.back()=='/'){
            path.pop_back();
        }
        int n = path.length();
        vector<string> arr;
        int i = 0;
        while(i<n){
            while(i<n && path[i]=='/'){
                i++;
            }
            int j = i;
            string temp = "";
            while(j<n && path[j]!='/'){
                temp+=path[j];
                j++;
            }
            if(temp.length()==0){
                break;
            }
            if(temp==".."){
                if(arr.size()){
                    arr.pop_back();   
                }
            }
            else if(temp!="."){
                arr.push_back(temp);
            }
            i = j;
        }
        if(arr.size()==0){
            return "/";
        }
        string ans = "";
        for(auto x:arr){
            ans+="/";
            ans+=x;
        }
        return ans;
    }
};