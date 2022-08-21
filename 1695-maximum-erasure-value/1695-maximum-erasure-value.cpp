class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=-1;
        int sum=0;
        unordered_set<int> s;
        int start=0,end=0;
        while(end<nums.size())
        {
            if(s.find(nums[end])!=s.end())
            {
                ans=max(ans,sum);
                while(s.find(nums[end])!=s.end())
                {
                    s.erase(nums[start]);
                    sum-=nums[start];
                    start++;
                }
            }
            else
            {
                s.insert(nums[end]);
                sum+=nums[end];
                end++;
            }
        }
        return max(ans,sum);
    }
};