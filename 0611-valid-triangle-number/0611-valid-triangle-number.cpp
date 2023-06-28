class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int i = 0;
        while(i<n && nums[i]==0) i++;
        if(i==n) return ans;
        for(;i<n;i++)
        {
            int j = i+1;
            int k = j+1;
            while(j<n)
            {
                if(k<n && nums[k]<nums[i]+nums[j]) k++;
                else
                {
                    ans+=(k-j-1);
                    j++;
                }
            }
        }
        return ans<0?0:ans;
    }
};