class Solution {
public:
    int nextGreaterElement(int n) {
        string s = "";
        while(n)
        {
            s+=(to_string(n%10));
            n/=10;
        }
        reverse(s.begin(),s.end());
        int si = s.size();
        int ind = si-1;
        while(ind>0 && (s[ind-1]-'0')>=(s[ind]-'0'))
            ind--;
        if(ind==0) return -1;
        int i = si-1;
        ind--;
        while(i>ind && (s[i]-'0')<=(s[ind]-'0'))
        i--;
        swap(s[i],s[ind]);
        sort(s.begin()+ind+1,s.end());
        long long an = 0;
        for(auto it:s)
            an = an*10 + (it-'0');
        if(an>INT_MAX) return -1;
        int ann = (int)an;
        return ann;
    }
};