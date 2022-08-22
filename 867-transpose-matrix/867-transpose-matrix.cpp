class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v (matrix[0].size(),vector<int>(matrix.size()));
        vector<int> a;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                v[j][i] = matrix[i][j];
            }
        }
        
        return v;
    }
};