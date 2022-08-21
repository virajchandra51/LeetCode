class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(auto it:arr)
            mp[it]++;
        vector<pair<int,int>> v;
        for(auto it:mp)
            v.push_back({it.second,it.first});
        int n = arr.size(); int nn = n/2;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int c=0;
        for(int i=0;i<v.size() && n>nn;i++)
        {
            n-=(v[i].first);
            c++;
        }
        return c;
    }
};