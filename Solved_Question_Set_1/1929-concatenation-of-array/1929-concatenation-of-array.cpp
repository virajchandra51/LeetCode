class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
        for(auto it:nums)
            v.push_back(it);
        for(auto it:nums)
            v.push_back(it);
        return v;
    }
};