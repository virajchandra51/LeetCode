class Solution {
public:
    int divide(int dividend, int divisor) {
        int c = 0;
        int si = 1;
        if(divisor==1) return dividend;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if((dividend<0 && divisor<0) || (dividend>=0 && divisor>0)){}
            else si=-1;
        long dividend1 = labs(dividend);
        long divisor1 = labs(divisor);
        while(dividend1>=divisor1)
        {
            long t = divisor1;
            int ans = 1;
            while((t<<1)<=dividend1)
            {
                t<<=1;
                ans<<=1;
            }
            dividend1-=t;
            c+=ans;
        }
        return si==-1?-c:c;
    }
    // 10 = 3*(2^1)+3*(2^0)+1 
};