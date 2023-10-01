class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int ans=0;
        int cnt=0;
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it=mp.end();it!=mp.begin();it--){
           // cout<<it.first<<"->"<<it.second<<" ";
            if(mini!=it->first){
                 ans=ans+it->second;
              
                cnt+=ans;
            }
           
        }
        return cnt;     
    }
};