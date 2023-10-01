class Solution {
public:
    int bitwiseComplement(int n) {
        string s="";
        if(n==0)
            return 1;
        while(n>0)
        {
            if(n&1)
                s+='1';
            else
                s+='0';
            n/=2;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                s[i]='0';
            else
                s[i]='1';
        }
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                ans+=pow(2,j);
            j++;
        }
        return ans;
    }
};