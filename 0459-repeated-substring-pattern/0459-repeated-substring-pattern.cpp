class Solution {
public:
    bool repeatedSubstringPattern(string a) {
        int n = a.size();
        vector<int> lps(n+1,0);
        for(int i=1;i<n;i++)
        {
            int j = lps[i-1];
            while(j>0 && a[j]!=a[i]) j=lps[j-1];
            if(a[i]==a[j]) j++;
            lps[i] = j;
        }
        if(!lps[n - 1]) return 0;
        int lastSub = n - lps[n - 1];
        return lps[n - 1]%lastSub == 0;
    }
};