class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<2*n;i++)
        {
            if(s.empty()==true)
                s.push(i%n);
            else
            {
                while(s.empty()==false && nums[s.top()]<nums[i%n])
                {
                    ans[s.top()] = nums[i%n];
                    s.pop();
                }
                s.push(i%n);
            }
        }
        return ans;
    }
};