class Solution {
public:
    bool hasAlternatingBits(int n) {
        int f;
        if(n%2)
            f=1;
        else
            f=0;
        while(n>0)
        {
            if(f==1)
            {
                if(n%2==0)
                    return false;
                else
                {
                    f=0;n/=2;
                }
            }
            else
            {
                if(n%2==1)
                    return false;
                else
                {
                    f=1;n/=2;
                }
            }
        }
        return true;
    }
};