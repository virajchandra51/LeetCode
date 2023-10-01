class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int,int> m1,m2,m3;
        for(auto it:nums1)
            m1[it]++;
        for(auto it:nums2)
            m2[it]++;
        for(auto it:nums3)
            m3[it]++;
        set<int> s;
        for(auto it:m1)
        {
            if(m2.find(it.first)!=m2.end() || m3.find(it.first)!=m3.end())
                s.insert(it.first);
        }
        for(auto it:m2)
        {
            if(m1.find(it.first)!=m1.end() || m3.find(it.first)!=m3.end())
                s.insert(it.first);
        }
        for(auto it:m3)
        {
            if(m1.find(it.first)!=m1.end() || m2.find(it.first)!=m2.end())
                s.insert(it.first);
        }
        vector<int> v;
        for(auto it:s)
            v.push_back(it);
        return v;
        
    }
};