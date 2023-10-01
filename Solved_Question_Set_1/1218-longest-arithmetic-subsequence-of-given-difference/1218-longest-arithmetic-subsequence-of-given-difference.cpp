class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int,int> m;
        for(auto it:arr)
        {
            if(m.find(it-d)!=m.end())
                m[it]=1+m[it-d];
            else m[it]=1;
        }
        int ans = 1;
        for(auto it:m) ans=max(ans,it.second);
        return ans;
    }
};