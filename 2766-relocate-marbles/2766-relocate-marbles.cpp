class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s;
        for(auto it:nums) s.insert(it);
        for(int i=0;i<moveFrom.size();i++)
        {
            s.erase(s.find(moveFrom[i]));
            s.insert(moveTo[i]);
        }
        vector<int> a;
        for(auto it:s) a.push_back(it);
        return a;
    }
};