class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        vector<int> v; 
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]!=nums[i])
                v.push_back(nums[i]);
        }
        int c=0;
        if(v.size()>2)
        {
            for(int i=1;i<v.size()-1;i++)
            {
                if(v[i]>v[i-1] && v[i]>v[i+1])
                    c++;
                else if(v[i]<v[i-1] && v[i]<v[i+1])
                    c++;
                else
                {}
            }
        }
        return c;
    }
};