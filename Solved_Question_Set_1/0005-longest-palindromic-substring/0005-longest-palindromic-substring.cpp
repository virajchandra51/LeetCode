class Solution {
public:
    pair<int,string> leng(string &s, int l, int r)
    {
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;
            r++;
        }
        return {r-l-1,s.substr(l+1,r-l-1)};
    }
    string longestPalindrome(string s) {
        int m = -1;
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            auto odd = leng(s,i,i);
            auto even = leng(s,i,i+1);
            if(odd.first>m)
            {
                m=odd.first;
                ans=odd.second;
            }
            if(even.first>m)
            {
                m=even.first;
                ans=even.second;
            }
        }
        return ans;
    }
};