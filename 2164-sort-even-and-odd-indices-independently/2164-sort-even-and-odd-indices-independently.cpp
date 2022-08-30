class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>a,b;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
                b.push_back(nums[i]);
            else
                a.push_back(nums[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        int l=0,r=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
                nums[i] = b[r++];
            else
                nums[i] = a[l++];
        }
        return nums;
    }
};