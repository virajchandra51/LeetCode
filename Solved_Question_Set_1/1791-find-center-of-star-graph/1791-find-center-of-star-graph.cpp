class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        mp[edges[0][0]]++;
        mp[edges[0][1]]++;
        mp[edges[1][0]]++;
        mp[edges[1][1]]++;
        for(auto it:mp)
        {
            if(it.second==2)
                return it.first;
        }
        return 0;
    }
};