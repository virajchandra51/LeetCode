class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        int f=-1;
        for(auto it:mp)
            f=max(f,it.second);
        vector<int> res;
        int d=INT_MAX;
        for(auto it:mp)
        {
            if(it.second==f)
                res.push_back(it.first);
        }
        for(int i=0;i<res.size();i++)
        {
            int i1=0,i2=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]==res[i])
                {
                    i1=j;break;
                }
            }
            for(int j=nums.size()-1;j>=0;j--)
            {
                if(nums[j]==res[i])
                {
                    i2=j;break;
                }
            }
            if((i2-i1+1)<d)
                d=i2-i1+1;
        }
        return d;
    }
};