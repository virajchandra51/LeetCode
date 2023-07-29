class Solution {
public:
    vector<vector<int>> ans;
    vector<int> d;
    void helper(vector<int> &a, int n, int k, int i)
    {
        if(i>=n)
        {
            if(k==0)
                ans.push_back(a);
            return;
        }
        helper(a,n,k,i+1);
        a.push_back(d[i]);
        helper(a,n,k-1,i+1);
        a.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        for(int i=1;i<=n;i++) d.push_back(i);
        vector<int> a;
        helper(a,n,k,0);
        return ans;
    }
};