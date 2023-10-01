class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k = 1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=k) return false;
            k++;
        }
        if(nums[nums.size()-1]!=(k-1)) return false;
        return true;
    }
};