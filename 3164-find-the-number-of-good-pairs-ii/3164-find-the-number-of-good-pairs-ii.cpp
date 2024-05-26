class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> freq(1000001, 0);
        map<int, int> mp;
        for (int x : nums2) 
            mp[x]++;
        for (auto x : mp)
            for (int i = x.first; i <= 1e6; i += x.first)
                freq[i] += x.second;
        long long res = 0;
        for (int x : nums1)
            if (x % k == 0)
                res += freq[x / k];
        return res;
    }
};