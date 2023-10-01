class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        for(int i=0;i<n;i++)
            if(n%(i+1)==0) 
            c+=pow(nums[i],2);
        return c;
    }
};