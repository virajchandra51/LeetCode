class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long int ans = 0;
        long long int sum = 0;
        map<int,int>mp;
        for(int i=0; i<=k-1; i++) {
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() >= m) {
            ans = max(ans, sum);
        }
        int last = k;
        int first = 0;
        while(last< nums.size()){
            mp[nums[first]]--;    
            if(mp[nums[first]] == 0) {
                mp.erase(nums[first]);
            }
            mp[nums[last]]++;
            sum = sum-nums[first]+nums[last];
            if(mp.size() >= m) {
                ans = max(ans, sum);
            }
            last++;
            first++;
        }
        return ans;
    }
};