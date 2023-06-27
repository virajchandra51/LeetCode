class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        set<pair<int,int>> s;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        long n = nums1.size();
        long m = nums2.size();
        int t = n*m;
        s.insert({0,0});
        p.push({nums1[0]+nums2[0],{0,0}});
        vector<vector<int>> a;
        while(k-- && !p.empty())
        {
            auto it = p.top();
            p.pop();
            int su = it.first;
            int i = it.second.first;
            int j = it.second.second;
            a.push_back({nums1[i],nums2[j]});
            if(i+1<n && s.find({i+1,j})==s.end())
            {p.push({nums1[i+1]+nums2[j],{i+1,j}});s.insert({i+1,j});}
            if(j+1<m && s.find({i,j+1})==s.end())
            {p.push({nums1[i]+nums2[j+1],{i,j+1}});s.insert({i,j+1});}
        }
        return a;
    }
};