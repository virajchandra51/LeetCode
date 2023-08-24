class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> preo(n,0);
        vector<int> pree(n,0);
        vector<int> sufo(n,0);
        vector<int> sufe(n,0);
        pree[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            if(i&1)
            {
                preo[i] = preo[i-1]+nums[i];
                pree[i] = pree[i-1];
            }
            else 
            {
                pree[i] = pree[i-1]+nums[i];
                preo[i] = preo[i-1];
            }
        }
        if(n&1)
        sufe[n-1] = nums[n-1];
        else sufo[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(i&1)
            {
                sufo[i] = sufo[i+1]+nums[i];
                sufe[i] = sufe[i+1];
            }
            else 
            {
                sufe[i] = sufe[i+1]+nums[i];
                sufo[i] = sufo[i+1];
            }
        }
        // for(auto it:preo) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:pree) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:sufo) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:sufe) cout<<it<<" ";
        // cout<<endl;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(sufe[i+1]==sufo[i+1]) c++;
            }
            else if(i==n-1)
            {
                if(pree[i-1]==preo[i-1]) c++;
            }
            else
            {
                if(pree[i-1]+sufo[i+1] == preo[i-1]+sufe[i+1]) c++;
            }
        }
        return c;
    }
};