class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> seive(n+1,1);
        for(int i=2;i*i<=n;i++)
        {
            if(seive[i])
            {
                for(int j=2*i;j<=n;j+=i)
                {
                    seive[j]=false;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=2;i<=(n/2);i++)
        {
            if(seive[i] && seive[n-i])
            {
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};