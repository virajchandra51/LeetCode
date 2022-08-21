class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int k=0;
        for(int i=0;i<matrix[0].size();i++)
        {
            int copy = matrix[k][i];
            int j=i;
            j++;
            k++;
            while(j<matrix[0].size() && k<matrix.size())
            {
                if(matrix[k][j]!=copy)
                    return false;
                k++;
                j++;
            }
            k=0;
        }
        k=0;
        for(int i=1;i<matrix.size();i++)
        {
            int copy = matrix[i][k];
            int j=i;
            j++;
            k++;
            while(j<matrix.size() && k<matrix[0].size())
            {
                if(matrix[j][k]!=copy)
                    return false;
                k++;
                j++;
            }
            k=0;
        }
        return true;
    }
};