class Solution {
public:
    bool isPos(vector<long long> nums, int num)
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>num)
                return false;
            long long diff = -nums[i]+num;
            nums[i]=num;
            nums[i+1]-=diff;
        }
        if(nums[nums.size()-1]>num) return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l =0, r=*max_element(nums.begin(),nums.end());
        vector<long long> num;
        for(auto it:nums) num.push_back(it);
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(isPos(num,mid)) r= mid; else l=mid+1;
            cout<<r<<" "<<l<<endl;
        }
        return r;
    }
};