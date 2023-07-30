class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums) m[it]++;
        int c = m.size();
        int s = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            map<int,int> mm;
            for(int j=i;j<n;j++) {mm[nums[j]]++;
            if(mm.size()==c) s++;}
        }
        return s;
    }
};