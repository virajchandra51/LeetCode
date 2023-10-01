class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(int i=0;i<arr2.size();i++)
        mp[arr2[i]]=i+1;
        vector<pair<int,int>> v;
        for(int i=0;i<arr1.size();i++)
        {
            if(mp.find(arr1[i])!=mp.end())
                v.push_back({mp[arr1[i]],arr1[i]});
            else
                v.push_back({INT_MAX,arr1[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto it:v)
            ans.push_back(it.second);
        return ans;
    }
};