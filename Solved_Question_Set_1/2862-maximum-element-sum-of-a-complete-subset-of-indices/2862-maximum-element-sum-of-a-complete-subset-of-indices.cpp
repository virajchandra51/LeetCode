class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long n = nums.size(), res = *max_element(nums.begin(), nums.end());
        vector<int> ps;
        long long number = 1;
        long long n2 = number * number;
        number = (number * 2) + 1;
        while ((n2 >= 1 && n2 <= 1e4)){
            ps.push_back(n2);
            n2 = n2 + number;
            number += 2;
        }
        for(int i=1; i<1e4; i++){
            long long sum = 0;
            for(int &num : ps){
                if(n>=1ll*i*num) sum += nums[i*num-1];
                else break;
            }
            res = max(res, sum);
        }
        return res;
    }
};