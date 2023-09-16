class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
           mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            ans=max(ans,i.second);
        }
        int x=n-ans;
        if(ans>x)
            return ans-x;
        return n%2;
    }
};