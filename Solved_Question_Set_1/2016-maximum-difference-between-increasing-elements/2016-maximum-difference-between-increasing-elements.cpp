class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int d=-1;
        for(int i=0;i<nums.size();i++)
        {
for(int j=i+1;j<nums.size();j++){
    if(nums[j]>nums[i]
      )
        d=max(d,nums[j]-nums[i]);
}}
        return d;
    }
    
};