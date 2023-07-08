class Solution {
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& c) {
        map<pair<int,int>,int> mp;
        vector<long long> res(5,0);
        for(auto it:c)
        {
            int x = it[0];
            int y = it[1];
            for(int i=x-1;i<=x;i++)
            {
                for(int j=y-1;j<=y;j++)
                {
                    if(i>=0 && i<n && j>=0 && j<m && i+1<n && j+1<m)
                    mp[{i,j}]++;
                }
            }
        }
        for(auto it:mp) res[it.second]++;
        res[0] = (long long)(n-1)*(long long)(m-1) - accumulate(res.begin(),res.end(),0LL);
        return res;
    }
};