class Solution {
public:
    bool helper(vector<int>& nums, int n, int k, int currsum, int st, vector<int>& vis, int tar)
    {
        if(k==1) return true;
        if(currsum==tar) return helper(nums,n,k-1,0,0,vis,tar);
        for(int i=st;i<n;i++)
        {
            if(i>0 && !vis[i-1] && nums[i]==nums[i-1])
                continue;
            if(!vis[i] && currsum+nums[i]<=tar)
            {
                vis[i]=1;
                if(helper(nums,n,k,currsum+nums[i],i+1,vis,tar)) return true;
                vis[i]=0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tar = 0;
        int n = nums.size();
        for(auto it:nums) tar+=it;
        if(k>tar || tar%k!=0) return false;
        tar/=k;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int> vis(n,0);
        return helper(nums,n,k,0,0,vis,tar);
    }
};