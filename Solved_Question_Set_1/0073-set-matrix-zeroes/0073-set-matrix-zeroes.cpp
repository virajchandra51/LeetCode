class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n,1);
        vector<int> col(m,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(row[i]==0)
            {
                for(int j=0;j<m;j++)
                    matrix[i][j]=0;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(col[i]==0)
            {
                for(int j=0;j<n;j++)
                    matrix[j][i]=0;
            }
        }
        return;
    }
};