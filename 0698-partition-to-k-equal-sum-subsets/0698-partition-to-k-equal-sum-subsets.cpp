class Solution {
public:
    bool helper(vector<int>& nums, vector<int>& vis, int target, int st, int n, int k, int currsum)
    {
        if(k==1) return true;
        if(currsum==target) return helper(nums,vis,target,0,n,k-1,0);
        for(int i=st;i<n;i++)
        {
            if(i>st && !vis[i-1] && nums[i]==nums[i-1]) continue; 
            if(vis[i]==0 && currsum+nums[i]<=target)
            {
                vis[i]=1;
                if(helper(nums,vis,target,i+1,n,k,currsum+nums[i])) return true;
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
        vector<int> vis(n,0);
        sort(nums.rbegin(),nums.rend());
        return helper(nums,vis,tar,0,n,k,0);
    }
};