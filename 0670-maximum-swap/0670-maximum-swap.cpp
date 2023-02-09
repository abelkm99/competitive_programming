class Solution {
public:
    int maximumSwap(int num) {
        int pMax[9]={0}, i;
        string sNum = to_string(num);
        
        for(i=sNum.length()-2, pMax[sNum.length()-1]=sNum.length()-1; i>=0; i--) {
            if(sNum[i]>sNum[pMax[i+1]]) pMax[i]=i;
            else pMax[i]=pMax[i+1];
        }
        
        i=0;
        while(i<sNum.length() && sNum[pMax[i]]==sNum[i]) i++;
        
        if(i<sNum.length()) {
            swap(sNum[i], sNum[pMax[i]]);
        }
        
        return stoi(sNum);
    }
};