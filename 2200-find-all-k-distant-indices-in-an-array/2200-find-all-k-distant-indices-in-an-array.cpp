class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arr;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                if(((i-j)<0?(j-i):(i-j))<=k && nums[j]==key) {
                    arr.push_back(i);
                    break;
                }
            }
        }
        return arr;
    }
};