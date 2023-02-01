class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rl,ru,cl,cu,sum;
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                rl=(i-k<0)?0:(i-k);
                cl=(j-k<0)?0:(j-k);
                ru=(i+k<mat.size()-1)?i+k:mat.size()-1;
                cu=(j+k<mat[0].size()-1)?j+k:mat[0].size()-1;
                sum=0;
                for(int r=rl;r<=ru;r++)
                {
                    for(int c=cl;c<=cu;c++)
                    {
                        sum+=mat[r][c];
                    }
                }
                answer[i][j]=sum;
            }
        }
        return answer;
    }
};