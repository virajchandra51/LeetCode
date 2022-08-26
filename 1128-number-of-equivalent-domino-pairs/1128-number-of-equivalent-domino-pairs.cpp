class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<pair<int,int>> v;
        for(int i=0;i<dominoes.size();i++)
        {
            if(dominoes[i][0]>dominoes[i][1])
                swap(dominoes[i][0],dominoes[i][1]);
        }
        for(auto it:dominoes)
        {
            v.push_back({it[0],it[1]});
        }
        map<pair<int,int>,int> mp;
        for(auto it:v)
            mp[it]++;
        long long ans=0;
        for(auto it:mp)
        {
            ans+=((it.second)*(it.second-1)/2);
        }
        return ans;
    }
};