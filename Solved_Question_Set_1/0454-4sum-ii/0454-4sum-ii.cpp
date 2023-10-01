class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> v;
        vector<vector<int>> vv;
        for(int a=0;a<nums.size();a++)
        {
            for(int b=a+1;b<nums.size();b++)
            {
                for(int c=b+1;c<nums.size();c++)
                {
                    for(int d=c+1;d<nums.size();d++)
                    {
                        if(nums[a]+nums[b]+nums[c]+nums[d]==target)
                        {
                            vector<int> aa;
                            aa.push_back(nums[a]);
                            aa.push_back(nums[b]);
                            aa.push_back(nums[c]);
                            aa.push_back(nums[d]);
                            sort(aa.begin(),aa.end());
                            v.insert(aa);
                        }
                    }
                }
            }
        }
        for(auto it:v)
            vv.push_back(it);
        return vv;
    }
};