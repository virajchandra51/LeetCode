class Solution {
public:
    vector<int> lps;
    bool helper(string a, string b, int k)
    {
        string s = "";
        for(int i=0;i<k;i++) s+=a;
        int i = 0;
        int j = 0;
        while(i<s.size())
        {
            if(s[i]==b[j])
            {
                i++;
                j++;
                if(j==b.size()) return true;
            }
            if(j==b.size()) break;
            if(i<s.size() && s[i]!=b[j])
            {
                if(j>0)
                j=lps[j-1];
                else
                {
                    i++;
                }
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n = b.size()/a.size();
        lps.resize(b.size(),0);
        for(int i=1;i<b.size();i++)
        {
            int j = lps[i-1];
            while(j>0 && b[i]!=b[j]) j=lps[j-1];
            if(b[i]==b[j]) j++;
            lps[i] = j;
        }
        for(auto it: lps) cout<<it<<" ";
        cout<<endl;
        if(helper(a,b,1)) return 1;
        if(helper(a,b,n)) return n;
        if(helper(a,b,n+1)) return n+1;
        if(helper(a,b,n+2)) return n+2;
        return -1;
    }
    // abcdabcdabcd
    // cdabcdab
};