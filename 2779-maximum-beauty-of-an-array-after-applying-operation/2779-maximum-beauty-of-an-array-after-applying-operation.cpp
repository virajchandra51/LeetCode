class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it:nums)
        {
            m[it-k]++;
            m[it+k+1]--;
        }
        int c = 0;
        int ans = 0;
        for(auto it:m)
        {
            c+=it.second;
            ans=max(ans,c);
        }
        return ans;
    }
};