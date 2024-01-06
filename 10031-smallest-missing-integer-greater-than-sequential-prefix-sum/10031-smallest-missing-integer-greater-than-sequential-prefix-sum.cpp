class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]!=1)
                break;
            sum+=nums[i];
        }
        while(true)
        {
            bool ok=false;
            for(auto ele : nums)
            {
                if(ele==sum)
                    ok=true;
            }
            
            if(!ok)
                return sum;
            sum++;
        }
        return -1;
    }
};