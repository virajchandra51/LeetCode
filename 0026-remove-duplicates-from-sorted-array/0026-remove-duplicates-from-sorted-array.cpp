class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            {nums[i-c]=nums[i];s.insert(nums[i]);}
            else
            {c++;
            }
        }
        return nums.size()-c;
    }
};