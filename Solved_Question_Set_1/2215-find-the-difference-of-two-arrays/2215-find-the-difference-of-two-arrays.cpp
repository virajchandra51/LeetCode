class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(auto it:nums1)
            s1.insert(it);
        for(auto it:nums2)
            s2.insert(it);
        vector<vector<int>> ans;
        vector<int> v;
        for(auto it:s1)
        {
            if(s2.find(it)==s2.end())
                v.push_back(it);
        }
        vector<int> a;
        ans.push_back(v);
        for(auto it:s2)
        {
            if(s1.find(it)==s1.end())
                a.push_back(it);
        }
        ans.push_back(a);
        return ans;
    }
};