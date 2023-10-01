class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if(2*k+1>n)return ans;
        long s=0;
        for(int i=0;i<(2*k+1);i++) s+=nums[i];
        int i=2*k+1;
        while(i<n)
        {
            ans[i-1-k]=s/(2*k+1);
            s-=nums[i-2*k-1];
            //cout<<nums[i-2*k-1];
            s+=nums[i];
            //cout<<nums[i]<<endl;
            i++;
        }
        ans[i-1-k]=s/(2*k+1);
        return ans;
    }
};