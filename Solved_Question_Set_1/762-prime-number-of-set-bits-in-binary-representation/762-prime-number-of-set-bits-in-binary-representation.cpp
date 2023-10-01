class Solution {
public:
    bool pri(int n)
    {
        if(n==1)
            return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int cb(int n)
    {
        int c=0;
        while(n>0)
        {
            if(n&1)
                c++;
            n=n>>1;
        }
        return c;
    }
    int countPrimeSetBits(int left, int right) {
        int c=0;
        for(int i=left;i<=right;i++)
        {
            if(pri(cb(i)))
            {c++;}
        }
        return c;
    }
};