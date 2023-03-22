class Solution {
public:
    double myPow(double x, int n) {
        bool xNeg = false;
        if(x<0 && abs(n&1)) 
        {
            xNeg = true;
            x=abs(x);
        }
        double ans = 1.0;
        double copyx = x;
        int copyn = n;
        n=abs(n);
        //1010
        while(n)
        {
            if(n&1)
            {
                ans*=copyx;
            }
            copyx*=copyx;
            n/=2;
        }
        if(copyn<0) ans=(1.0/ans);
        if(xNeg) ans*=-1;
        cout<<ans<<endl;
        return ans;
    }
};