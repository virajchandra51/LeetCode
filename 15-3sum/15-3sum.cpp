class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;
        set<vector<int>> v;
        vector<int> a(3);
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int k=i+1;k<nums.size();k++)
            {
                if(mp.find(-nums[i]-nums[k])!=mp.end())
                {
                    a[0]=nums[i]; a[1] = nums[k]; a[2]= -nums[i]-nums[k];
                    sort(a.begin(),a.end()); 
                    v.insert(a);
                }
            }
            mp[nums[i]]=1;
        }
        vector<vector<int>> ss;
        for(auto it:v)
            ss.push_back(it);
        return ss;
    }
};