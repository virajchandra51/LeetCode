class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &a, int k, int n,int start)
    {
        if(a.size()==k && n==0)
        {
            ans.push_back(a);
            return;
        }
        for(int i=start;i<=9;i++)
        {
            a.push_back(i);
            dfs(a,k,n-i,i+1);
            a.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        dfs(a,k,n,1);
        return ans;
    }
};