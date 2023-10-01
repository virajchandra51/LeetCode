class Solution {
public:
    int arraySign(vector<int>& nums) {
        int x = 1;
        for(auto it:nums)
        {
            if(it>0)
                continue;
            else if(it<0 && x<0)
                x=1;
            else if(it<0 && x>0)
                x=-1;
            else
            {
                x=0;break;
            }
        }
        return x;
    }
};