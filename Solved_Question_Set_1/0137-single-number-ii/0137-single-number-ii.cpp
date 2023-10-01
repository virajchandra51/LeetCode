class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int mask = 1;
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            int c = 0;
            for(auto it:nums)
            {
                if(it&mask) c++;
            }
            if(c%3) ans|=mask;
            mask<<=1;
        }
        return ans;
    }
};