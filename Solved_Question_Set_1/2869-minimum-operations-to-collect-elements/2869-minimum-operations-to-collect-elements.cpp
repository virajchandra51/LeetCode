class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> vis(k,0);
        int j = nums.size()-1;
        int c = 0;
        while(j>=0)
        {
            if(nums[j]<=k)
            vis[nums[j]-1]=1;
            c++;
            int f=1;
            for(auto it:vis) f&=it;
            if(f) 
            {
                return c;
            }
            j--;
        }
        return c;
    }
};