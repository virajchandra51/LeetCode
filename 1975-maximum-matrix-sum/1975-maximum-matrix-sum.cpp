class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int f=0;
        int c=0;
        int m = INT_MAX;
        for(auto it:matrix)
        {
            for(auto i:it)
            {
                ans+=abs(i);
                if(i<0) c++;
                if(i==0) f=1;
                m = min(m,abs(i));
            }
        }
        if(f==1 || !(c&1)) return ans;
        return ans-2*m;
    }
};