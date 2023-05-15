class Solution {
public:
    int mySqrt(int x) {
        long l=1,r=x;
        if(x==1) return 1;
        if(x<2) return 0;
        int ans;
        while(l<=r)
        {
            int m = (l+r)>>1;
            if((m)<=(x/m))
            {
                ans=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return ans;
    }
};