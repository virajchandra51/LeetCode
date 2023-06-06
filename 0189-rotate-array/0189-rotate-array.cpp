class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int st = start;
        int currR = 0;
        int t = nums[start];
        int n = nums.size();
        int ni;
        while(currR<n)
        {
            do{
                ni = (start+k)%n;
                start = ni;
                int tt = nums[ni];
                nums[ni] = t;
                t = tt;
                currR++;
            } while(ni!=st);
            st++;
            start=st;
            t=nums[start];
        }
        return;
    }
};