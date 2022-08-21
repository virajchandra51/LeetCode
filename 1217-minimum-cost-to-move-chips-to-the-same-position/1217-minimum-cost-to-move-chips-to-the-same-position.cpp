class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        map<int,int> mp;
        for(auto it:position)
            mp[it]++;
        int c=INT_MAX;
        vector<pair<int,int>> v;
        for(auto it:mp)
            v.push_back({it.first,it.second});
        for(int i=0;i<v.size();i++)
        {
            int cc=0;
            for(int j=0;j<v.size();j++)
            {
                if(i==j)
                    continue;
                else
                {
                    if(abs(v[i].first-v[j].first)&1)
                        cc+=v[j].second;
                }
            }
            c=min(c,cc);
        }
        return c;
    }
};