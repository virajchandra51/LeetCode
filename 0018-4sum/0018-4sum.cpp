class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> vv;
        int n = nums.size();
        for(int a=0;a<n-3;a++)
        {
            if(a!=0 && nums[a]==nums[a-1]) continue;
            for(int b=a+1;b<n;b++)
            {
                if(b>a+1 && nums[b]==nums[b-1]) continue;
                int c = b+1;
                int d = n-1;
                long tar = target;
                tar-=nums[a];
                tar-=nums[b];
                while(c<d)
                {
                    if(nums[c]+nums[d]==tar)
                    {
                        vv.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++;
                        d--;
                        while(c<d && nums[c]==nums[c-1]) c++;
                        while(c<d && nums[d]==nums[d+1]) d--;
                    }
                    else if(nums[c]+nums[d]<tar)
                        c++;
                    else d--;
                }
            }
        }
        return vv;
    }
};