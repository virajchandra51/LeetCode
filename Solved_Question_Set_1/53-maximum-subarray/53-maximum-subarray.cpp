class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int max_ending =0;
        for(auto it:nums)
        {
            max_ending+=it;
            if(max_ending>ans)
                ans=max_ending;
            if(max_ending<0)
                max_ending=0;
        }
        return ans;
    }
};