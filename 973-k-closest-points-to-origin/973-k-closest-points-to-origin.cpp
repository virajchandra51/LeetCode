class Solution {
public:
    int getD(int x, int y)
    {
        return pow(x,2) + pow(y,2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,vector<vector<int>>> mp;
        for(auto it:points)
            mp[getD(it[0],it[1])].push_back(it);
        vector<vector<int>> v;
        for(auto it:mp)
        {
            for(auto i:it.second)
            {
                if(k==0)
                    return v;
                k--;
                v.push_back(i);
            }
        }
        return v;
    }
};