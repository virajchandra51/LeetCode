class Solution {
public:
    vector<int> a,b;
    int k = 0;
    Solution(vector<int>& nums) {
        a=nums;
        b=nums;
    }
    
    vector<int> reset() {
        return a;
    }
    
    vector<int> shuffle() {
        next_permutation(b.begin(),b.end());
        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */