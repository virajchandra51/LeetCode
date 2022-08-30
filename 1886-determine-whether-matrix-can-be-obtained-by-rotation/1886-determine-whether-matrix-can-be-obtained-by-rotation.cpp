class Solution {
public:
    void transpose(vector<vector<int>>& m){
        for(int i=0;i<m.size();i++)
        {
            for(int j=i+1;j<m.size();j++)
            {
                int temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }
        }
    }
    void reflect(vector<vector<int>>& m){
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<m.size()/2;j++)
            {
                int temp = m[i][j];
                m[i][j] = m[i][m.size()-j-1];
                m[i][m.size()-j-1] = temp;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)
            return true;
        transpose(mat);
        reflect(mat);
        if(mat==target)
            return true;
        transpose(mat);
        reflect(mat);
        if(mat==target)
            return true;
        transpose(mat);
        reflect(mat);
        if(mat==target)
            return true;
        return false;
    }
};