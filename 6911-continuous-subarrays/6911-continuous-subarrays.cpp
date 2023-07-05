class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        int j = 0;
        map<int,int> m;
        int n = nums.size();
        while(j<n)
        {
            m[nums[j]]++;
            while(m.size()>1 && i<n && i<j && m.rbegin()->first-m.begin()->first>2)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};