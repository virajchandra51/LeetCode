class Solution {
public:
    static bool comp(pair<int,int>& a, pair<int,int> &b)
    {
        if(a.second!=b.second) return a.second<b.second;
        return a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++)
        {
            int c = 0;
            for(int j=0;j<mat[0].size();j++) c+=mat[i][j];
            v.push_back({i,c});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(v[i].first);
        return ans;
    }
};