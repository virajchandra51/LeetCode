class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> m(31,0);
        long long sum = 0;
        int c = 0;
        for(auto it:nums)
        {
            m[log2(it)]++;
            sum+=it;
        }
        if(sum<target) return -1;
        for(int i=0;i<31;i++)
        {
            if(target&(1<<i))
            {
                if(m[i]>0)
                {
                    m[i]--;
                }
                else
                {
                    int j = i;
                    while(j<31 && m[j]==0) j++;
                    for(int k=j;k>i;k--)
                    {
                        m[k]--;
                        c++;
                        m[k-1]+=2;
                    }
                    m[i]--;
                }
            }
            if(i+1<31)
            {m[i+1] += m[i]/2;m[i]=0;}
        }
        return c;
    }
};