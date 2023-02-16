class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        if(s.length()==1){
            return mp[s[0]];
        }
        int i = 0;
        while(i<s.length()-1){
            if(s[i]=='I'){
                if(s[i+1] == 'V'){
                    ans+=4;
                    i+=2;
                    continue;
                }
                if(s[i+1] == 'X'){
                    ans+=9;
                    i+=2;
                    continue;
                }
                ans+=mp[s[i]];
                i++;
                continue;
            }
            else if(s[i]=='X'){
                if(s[i+1] == 'L'){
                    ans+=40;
                    i+=2;
                    continue;
                }
                if(s[i+1] == 'C'){
                    ans+=90;
                    i+=2;
                    continue;
                }
                ans+=mp[s[i]];
                i++;
                continue;
            }
            else if(s[i]=='C'){
                if(s[i+1] == 'D'){
                    ans+=400;
                    i+=2;
                    continue;
                }
                if(s[i+1] == 'M'){
                    ans+=900;
                    i+=2;
                    continue;
                }
                ans+=mp[s[i]];
                i++;
                continue;
            }
            else{
                ans+=mp[s[i]];
                i++;
                continue;
            }
        }
        while(i<s.length()){
            ans+=mp[s[i]];
            i++;
        }
        return ans;
    }
};