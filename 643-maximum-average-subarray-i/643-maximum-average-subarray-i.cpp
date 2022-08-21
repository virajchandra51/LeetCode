class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        vector<int> n;
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        n.push_back(sum);
        for(int i=k;i<nums.size();i++)
        {
            sum+=nums[i];
            sum-=(nums[i-k]);
            n.push_back(sum);
        }
        for(int i=0;i<n.size();i++)
            ans=max(ans,n[i]*1.0/k);
        return ans;
    }
};