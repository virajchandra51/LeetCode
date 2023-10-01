class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]].push_back(i);
        set<int> s;
        int ans = INT_MAX;
        for(auto it:nums)
        {
            if(s.find(it)!=s.end())
                continue;
            else
            {
                int a = INT_MIN;
                if(m[it].size()==1)
                {
                    a=max(a,max(m[it][0],n-m[it][0]-1));
                    ans=min(ans,a);
                    continue;
                }
                for(int i=0;i<m[it].size()-1;i++)
                {
                    int fi = m[it][i];
                    int se = m[it][i+1];
                    int diff = se-fi-1;
                    if(diff==1)
                    {
                        a=max(a,1);
                        continue;
                    }
                    diff = ceil(diff*1.0/2.0);
                    a=max(a,diff);
                }
                int diff = n-m[it][m[it].size()-1]-1+m[it][0];
                if(diff==1)
                {
                    a=max(a,1);
                }
                else
                {
                    diff = ceil(diff*1.0/2.0);
                    a=max(a,diff);
                }
                ans=min(ans,a);
            }  
            s.insert(it);
        }
        return ans;
    }
};