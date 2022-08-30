class Solution {
public:
    int secondHighest(string s) {
        int d=-1;
        for(auto it:s)
        {
            if(it>='0' && it<='9')
                d=max(d,it-48);
        }
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        for(auto it:s)
        {
            if(it>='0' && it<='9' && (it-48)<d)
                return it-48;
        }
        return -1;
    }
};