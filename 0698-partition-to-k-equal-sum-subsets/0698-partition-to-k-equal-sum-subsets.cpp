class Solution {
public:
    bool ans = false;
    void helper(vector<int>& nums, vector<long long>& sum, int target, int i, int n, int k)
    {
        if(i>=n)
        {
            ans=true;
            return;
        }
        for(int kk=0;kk<k;kk++)
        {
            if(sum[kk]+nums[i]<=target)
            {
                sum[kk]+=nums[i];
                helper(nums,sum,target,i+1,n,k);
                sum[kk]-=nums[i];
            }
            if(sum[kk]==0) break;
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tar = 0;
        int n = nums.size();
        for(auto it:nums) tar+=it;
        if(k>tar || tar%k!=0) return false;
        tar/=k;
        vector<long long> sum(k,0);
        helper(nums,sum,tar,0,n,k);
        return ans;
    }
};