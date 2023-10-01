class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]==nums2[0])
                dp[0][i] = 1;
                ans=max(ans,dp[0][i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]==nums1[0])
                dp[i][0] = 1;
            ans=max(ans,dp[i][0]);
        }
        for(int i=1;i<nums2.size();i++)
        {
            for(int j=1;j<nums1.size();j++)
            {
                if(nums2[i]==nums1[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};