class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> v;
        for(int i=mat.size()-1;i>0;i--)
        {
            int j=i; int k=0;
            vector<int> a;
            while(j<mat.size() && k<mat[0].size())
            {
                a.push_back(mat[j][k]);
                j++;k++;
            }
            v.push_back(a);
        }
        for(int i=0;i<mat[0].size();i++)
        {
            vector<int> a;
            int j=i;int k=0;
            while(j<mat[0].size() && k<mat.size())
            {
                a.push_back(mat[k][j]);
                j++;
                k++;
            }
            v.push_back(a);
        }
        for(int i=0;i<v.size();i++)
            sort(v[i].begin(),v[i].end());
        
        int l=0;
        for(int i=mat.size()-1;i>0;i--)
        {
            int j=i; int k=0;
            int kk=0;
            while(j<mat.size() && k<mat[0].size())
            {
                mat[j][k] = v[l][kk++];
                j++;k++;
            }
            l++;
        }
        for(int i=0;i<mat[0].size();i++)
        {
            int j=i;int k=0;
            int kk=0;
            while(j<mat[0].size() && k<mat.size())
            {
                mat[k][j] = v[l][kk++];
                j++;
                k++;
            }
            l++;
        }
        
        return mat;
    }
};