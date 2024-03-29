class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        int c = 0;
        while(j<n)
        {
            if(s[j]=='T')
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                if(c<k)
                {
                    c++;
                    ans=max(ans,j-i+1);
                    j++;
                }
                else
                {
                    while(c>=k && i<n && s[i]!='F')
                    {
                        i++;
                    }
                    i++;
                    ans=max(ans,j-i+1);
                    j++;
                }
            }
        }
        i=0;
        j=0;
        c=0;
        while(j<n)
        {
            if(s[j]=='F')
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                if(c<k)
                {
                    c++;
                    ans=max(ans,j-i+1);
                    j++;
                }
                else
                {
                    while(c>=k && i<n && s[i]!='T')
                    {
                        i++;
                    }
                    i++;
                    ans=max(ans,j-i+1);
                    j++;
                }
            }
        }
        return ans;
    }
};