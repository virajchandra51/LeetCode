class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i=0;i<k;i++)
        {
            if(q.empty()==true) q.push_back(i);
            else
            {
                while(q.empty()==false && nums[i]>=nums[q.back()])
                    q.pop_back();
                q.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=k;i<nums.size();i++)
        {
            ans.push_back(nums[q.front()]);
            if(q.empty()==true) q.push_back(i);
            else
            {
                while(q.empty()==false && q.front()<=(i-k)) q.pop_front();
                while(q.empty()==false && nums[i]>=nums[q.back()])
                    q.pop_back();
                q.push_back(i);
            }
        }
        if(q.empty()==false)
        ans.push_back(nums[q.front()]);
        return ans;
    }
};