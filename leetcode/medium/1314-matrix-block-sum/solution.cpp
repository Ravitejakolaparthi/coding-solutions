class Solution {
public:
    long long int sum(int i,int j,int k,vector<vector<int>>&mat)
    {
            long long int add = 0;
            int o  = 0;
            int p = 0;
            for(o = i-k;o<=i+k;o++)
            {
                if(o<0 || o >=mat.size())
                continue;
                for(p = j-k;p<=j+k;p++)
                {
                   if(p<0 || p>=mat[0].size())
                    continue;
                    else
                    {
                        add+=mat[o][p];
                    }
                }
            }
            return add;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>answers(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                answers[i][j] = sum(i,j,k,mat);
            }
        }
        return answers;
    }
};