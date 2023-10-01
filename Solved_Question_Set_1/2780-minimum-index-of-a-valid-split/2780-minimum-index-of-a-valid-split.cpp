class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums) m[it]++;
        int f = 0;
        int n;
        for(auto it:m)
        {
            if(it.second>f)
            {
                f=it.second;
                n=it.first;
            }
        }
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==n)
                c++;
            int f1 = f-c;
            if(c*2>(i+1) && f1*2>(nums.size()-i-1))
                return i;
        }
        return -1;
    }
};