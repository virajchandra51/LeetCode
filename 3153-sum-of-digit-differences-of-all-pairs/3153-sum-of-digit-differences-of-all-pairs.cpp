class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        while(nums[0]>0)
        {
            vector<long long> c(10,0);
            for(auto &i:nums)
            {
                c[i%10]++;
                i/=10;
            }
            for(int i=0;i<c.size();i++)
            {
                for(int j=i+1;j<c.size();j++)
                    ans+=c[i]*c[j]*1LL;
            }
        }
        return ans;
    }
};