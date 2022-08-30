class Solution {
public:
    int c(int n)
    {
        int cc=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(n/i==i)
                    cc++;
                else
                    cc+=2;
            }
        }
        return cc;
    }
    bool isThree(int n) {
        if(c(n)==3)
            return true;
        return false;
    }
};