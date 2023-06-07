class Solution {
public:
    int minFlips(int a, int b, int c) {
        int o = a^b;
        int aa = a|b;
        int bb = a&b;
        int ans=0;
        while(aa>0 || bb>0 || o>0 || c>0)
        {
            if(c%2==1)
            {
                if(aa%2==0)
                {
                    ans++;
                }
            }
            else
            {
                if(bb%2==1)
                {
                    ans+=2;
                }
                else if(o%2==1)
                {
                    ans++;
                }
            }
            c>>=1;
            o>>=1;
            aa>>=1;
            bb>>=1;
        }
        return ans;
    }
};
