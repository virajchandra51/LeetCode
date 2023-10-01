class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<string,vector<int>> mp;
        vector<string> a = s;
        for(int i=0;i<s.size();i++)
            sort(s[i].begin(),s[i].end());
        for(int i=0;i<s.size();i++)
            mp[s[i]].push_back(i);
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            vector<string> b;
            for(auto i:it.second)
                b.push_back(a[i]);
            ans.push_back(b);
        }
        return ans;
    }
};