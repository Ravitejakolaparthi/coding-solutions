class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>v;
       
        for(int i = 0;i<matrix.size();i++)
        {
             int d= 0;
            for(int j = 0;j<matrix[i].size();j++)
            {
                d+=matrix[i][j];
            }
            v.push_back(d);
        }
        return v;
    }
};